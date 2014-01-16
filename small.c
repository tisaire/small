#include <linux/module.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>
#include <asm/types.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Device Driver Demo");
MODULE_AUTHOR("Xavier Tisaire");

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
static int gpmc_init(int mode);

static struct file_operations fops =
{
		.owner =  THIS_MODULE,
		.read = dev_read,
		.open = dev_open,
		.write = dev_write,
		.release = dev_rls,
};

static int gpmc_init(int mode)
{

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
