#include <linux/module.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <linux/ioctl.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <asm/types.h>
#include <asm/io.h>
#include <linux/ioport.h>

#include "hw_cm_per.h"
#include "hw_gpmc.h"
#include "soc_AM335x.h"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Device Driver Demo");
MODULE_AUTHOR("Xavier Tisaire");


#define CS_ON	0
#define CS_OFF	4
#define ADV_ON	0
#define ADV_OFF	1
#define WR_CYC	5
#define WR_ON	2
#define WR_OFF ((CS_ON + CS_OFF)-WR_ON)
#define RD_CYC	5
#define OE_ON	2
#define OE_OFF ((CS_ON + CS_OFF)-OE_ON)
#define RD_ACC_TIME 4
#define WRDATAONADMUX 2  //number of cycle before taking control of data bus (when add/data multiplexing)


char * gDrvrName = "small";

dev_t dev = 0;
struct cdev c_dev;
int small_major =   89;
int small_minor =   0;
static char msg[100]={0};
static short readPos=0 ;
static int times =0 ;

static int dev_open(struct inode *inod,struct file *fil);
static int dev_rls(struct inode *inod,struct file *fil);
static ssize_t dev_read(struct file *filp,char *buff,size_t len,loff_t *off);
static ssize_t dev_write(struct file *filp,const char *buff,size_t len,loff_t *off);
static int gpmc_init();
void orShortRegister(unsigned short int value, volatile unsigned int * port);

static struct file_operations fops =
{
		.owner =  THIS_MODULE,
		.read = dev_read,
		.open = dev_open,
		.write = dev_write,
		.release = dev_rls,
};

void orShortRegister(unsigned short int value, volatile unsigned int * port){
	unsigned short oldVal ;
	oldVal = ioread32(port);
	iowrite32(oldVal | value, port);
}

static int gpmc_init()
{

	unsigned int temp = 0;
		unsigned short int csNum = 0 ;
		volatile unsigned int * gpmc_reg_pointer ;

		printk("Configuring GPMC for non muxed access \n");


		if (check_mem_region(SOC_GPMC_0_REGS, 720)) {
		    printk("%s: memory already in use\n", gDrvrName);
		    return -EBUSY;
		}
		request_mem_region(SOC_GPMC_0_REGS, 720, gDrvrName);
		gpmc_reg_pointer = ioremap_nocache(SOC_GPMC_0_REGS,  720);



		printk("GPMC_REVISION value :%x \n", ioread32(gpmc_reg_pointer + GPMC_REVISION/4));

		orShortRegister(GPMC_SYSCONFIG_SOFTRESET, gpmc_reg_pointer + GPMC_SYSCONFIG/4 ) ;
		printk("Trying to reset GPMC \n");
		printk("GPMC_SYSSTATUS value :%x \n", ioread32(gpmc_reg_pointer + GPMC_SYSSTATUS/4));
		while((ioread32(gpmc_reg_pointer + GPMC_SYSSTATUS/4) &
			GPMC_SYSSTATUS_RESETDONE) == GPMC_SYSSTATUS_RESETDONE_RSTONGOING){
			printk("GPMC_SYSSTATUS value :%x \n", ioread32(gpmc_reg_pointer +
			GPMC_SYSSTATUS/4));
		}
		printk("GPMC reset \n");
		temp = ioread32(gpmc_reg_pointer + GPMC_SYSCONFIG/4);
		temp &= ~GPMC_SYSCONFIG_IDLEMODE;
		temp |= GPMC_SYSCONFIG_IDLEMODE_NOIDLE << GPMC_SYSCONFIG_IDLEMODE_SHIFT;
		iowrite32(temp, gpmc_reg_pointer + GPMC_SYSCONFIG/4);
		iowrite32(0x00, gpmc_reg_pointer + GPMC_IRQENABLE/4) ;
		iowrite32(0x00, gpmc_reg_pointer + GPMC_TIMEOUT_CONTROL/4);


		iowrite32((0x0 |
		(GPMC_CONFIG1_0_DEVICESIZE_SIXTEENBITS <<
			GPMC_CONFIG1_0_DEVICESIZE_SHIFT ) |
		(GPMC_CONFIG1_0_ATTACHEDDEVICEPAGELENGTH_FOUR <<
			GPMC_CONFIG1_0_ATTACHEDDEVICEPAGELENGTH_SHIFT ) |
		(GPMC_CONFIG1_0_MUXADDDATA_NONMUX << GPMC_CONFIG1_0_MUXADDDATA_SHIFT )),
		gpmc_reg_pointer + GPMC_CONFIG1(csNum)/4) ;	//Address/Data non-multiplexed


		iowrite32((0x0 |
	    	(CS_ON) |	// CS_ON_TIME
	        (CS_OFF << GPMC_CONFIG2_0_CSRDOFFTIME_SHIFT) |	// CS_DEASSERT_RD
	        (CS_OFF << GPMC_CONFIG2_0_CSWROFFTIME_SHIFT)),	//CS_DEASSERT_WR
		gpmc_reg_pointer + GPMC_CONFIG2(csNum)/4)  ;

		iowrite32((0x0 |
	        (ADV_ON << GPMC_CONFIG3_0_ADVONTIME_SHIFT) | //ADV_ASSERT
		(ADV_OFF << GPMC_CONFIG3_0_ADVRDOFFTIME_SHIFT) | //ADV_DEASSERT_RD
		(ADV_OFF << GPMC_CONFIG3_0_ADVWROFFTIME_SHIFT)), //ADV_DEASSERT_WR
		gpmc_reg_pointer + GPMC_CONFIG3(csNum)/4) ;

		iowrite32( (0x0 |
		    (OE_ON << GPMC_CONFIG4_0_OEONTIME_SHIFT) |	//OE_ASSERT
		    (OE_OFF << GPMC_CONFIG4_0_OEOFFTIME_SHIFT) |	//OE_DEASSERT
		    (WR_ON << GPMC_CONFIG4_0_WEONTIME_SHIFT)| //WE_ASSERT
		    (WR_OFF << GPMC_CONFIG4_0_WEOFFTIME_SHIFT)), //WE_DEASSERT
		gpmc_reg_pointer + GPMC_CONFIG4(csNum)/4)  ;

		iowrite32((0x0 |
		    (RD_CYC << GPMC_CONFIG5_0_RDCYCLETIME_SHIFT)|	//CFG_5_RD_CYCLE_TIM
		    (WR_CYC << GPMC_CONFIG5_0_WRCYCLETIME_SHIFT)|	//CFG_5_WR_CYCLE_TIM
		    (RD_ACC_TIME << GPMC_CONFIG5_0_RDACCESSTIME_SHIFT)),	// CFG_5_RD_ACCESS_TIM
		gpmc_reg_pointer + GPMC_CONFIG5(csNum)/4)  ;

		iowrite32( (0x0 |
			(0 << GPMC_CONFIG6_0_CYCLE2CYCLESAMECSEN_SHIFT) |
			(0 << GPMC_CONFIG6_0_CYCLE2CYCLEDELAY_SHIFT) | //CYC2CYC_DELAY
		    (WRDATAONADMUX << GPMC_CONFIG6_0_WRDATAONADMUXBUS_SHIFT)| //WR_DATA_ON_ADMUX
		    (0 << GPMC_CONFIG6_0_WRACCESSTIME_SHIFT)), //CFG_6_WR_ACCESS_TIM
		gpmc_reg_pointer + GPMC_CONFIG6(csNum)/4) ;

		iowrite32(( 0x09 << GPMC_CONFIG7_0_BASEADDRESS_SHIFT) | //CFG_7_BASE_ADDR
	        (0x1 << GPMC_CONFIG7_0_CSVALID_SHIFT) |
	        (0x0f << GPMC_CONFIG7_0_MASKADDRESS_SHIFT), //CFG_7_MASK
		gpmc_reg_pointer + GPMC_CONFIG7(csNum)/4);
		iounmap(gpmc_reg_pointer);
		release_mem_region(SOC_GPMC_0_REGS, 720);
		return 1;
}


int small_init(void)
{
	int result,err;
	struct small_dev* sm_dev = 0;



	printk(KERN_ALERT "allocating chrdev...\n");
	result = alloc_chrdev_region(&dev, small_minor, 1,"small");
	small_major = MAJOR(dev);
	if (result < 0) {
		printk(KERN_WARNING "small: can't get major %d\n", small_major);
		return result;
	}

	printk(KERN_ALERT "setting up chrdev with MAJOR %d MINOR %d...\n",small_major,small_minor);
	cdev_init(&c_dev, &fops);
	c_dev.owner = THIS_MODULE;
	c_dev.ops = &fops;
	err = cdev_add (&c_dev, dev, 1);
	/* Fail gracefully if need be */
	if (err)
		printk(KERN_NOTICE "Error %d adding small", err);

	gpmc_init();

	return err;
}

static ssize_t dev_open(struct inode *inod,struct file *fil)
{
	printk(KERN_ALERT "opening...\n");
	times++;
	printk(KERN_ALERT"Device opened %d time5\n",times);
	return 0;
}

static ssize_t dev_read(struct file *filp,char *buff,size_t len,loff_t *off)
{
	short count = 0;
	printk(KERN_ALERT "reading...\n");
	while (len && (msg[readPos]!= 0))
	{
		put_user(msg[readPos],buff++);
		count++;
		len--;
		readPos++;
	}
	return count;
}

static ssize_t dev_write(struct file *filp,const char *buff,size_t len,loff_t *off)
{
	short ind = len-1;
	short count = 0;
	memset(msg,0,100);
	readPos=0;
	printk(KERN_ALERT "writting...\n");
	while(len>0)
	{
		msg[count++] = buff[ind--];
		len--;
	}
	return count;
}

static int dev_rls(struct inode *inod,struct file *fil)
{
	printk(KERN_ALERT"Device %d released\n",MAJOR(dev));
	return 0;
}
static int dev_close(struct inode *inod,struct file *fil)
{
	cdev_del(&c_dev);
	unregister_chrdev_region(dev,1);
	printk(KERN_ALERT"Device %d closed\n",MAJOR(dev));
	return 0;
}

module_init(small_init);
module_exit(dev_close);
