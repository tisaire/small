#include <mach/am35xx.h>
#include <plat/gpmc.h>
#include <mux.h>
#include <plat/gpmc.h>
#include <mux34xx.h>
#include <asm/types.h>
#include <asm-generic/int-ll64.h>
#include <mach/board-am335xevm.h>
//#include <>

#define GPMC_muxed_16bit 1
#define GPMC_non_muxed_16bit 0

void PINMUX_Config(u8 mode)
{
	if(mode == GPMC_muxed_16bit)
	{
	AM33XX_MUX(GPMC_AD0, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD0 */;
	AM33XX_MUX(GPMC_AD1, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD1 */;
	AM33XX_MUX(GPMC_AD2, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD2 */;
	AM33XX_MUX(GPMC_AD3, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD3 */;
	AM33XX_MUX(GPMC_AD4, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD4 */;
	AM33XX_MUX(GPMC_AD5, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD5 */;
	AM33XX_MUX(GPMC_AD6, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD6 */;
	AM33XX_MUX(GPMC_AD7, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD7 */;
	AM33XX_MUX(GPMC_AD8, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD8 */;
	AM33XX_MUX(GPMC_AD9, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD9 */;
	AM33XX_MUX(GPMC_AD10, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD10 */;
	AM33XX_MUX(GPMC_AD11, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD11 */;
	AM33XX_MUX(GPMC_AD12, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD12 */;
	AM33XX_MUX(GPMC_AD13, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD13 */;
	AM33XX_MUX(GPMC_AD14, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD14 */;
	AM33XX_MUX(GPMC_AD15, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD15 */;
	AM33XX_MUX(GPMC_A0, (AM33XX_PIN_INPUT | OMAP_MUX_5 )) /* PR1_MII_MT1_CLK */;
	AM33XX_MUX(GPMC_A1, (AM33XX_PIN_OUTPUT | OMAP_MUX_5 )) /* PR1_MII1_TXD3 */;
	AM33XX_MUX(GPMC_A2, (AM33XX_PIN_OUTPUT | OMAP_MUX_5 )) /* PR1_MII1_TXD2 */;
	AM33XX_MUX(GPMC_A3, (AM33XX_PIN_OUTPUT | OMAP_MUX_5 )) /* PR1_MII1_TXD1 */;
	AM33XX_MUX(GPMC_A4, (AM33XX_PIN_OUTPUT | OMAP_MUX_5 )) /* PR1_MII1_TXD0 */;
	AM33XX_MUX(GPMC_A5, (AM33XX_PIN_INPUT | OMAP_MUX_5 )) /* PR1_MII1_RXD3 */;
	AM33XX_MUX(GPMC_A6, (AM33XX_PIN_INPUT | OMAP_MUX_5 )) /* PR1_MII1_RXD2 */;
	AM33XX_MUX(GPMC_A7, (AM33XX_PIN_INPUT | OMAP_MUX_5 )) /* PR1_MII1_RXD1 */;
	AM33XX_MUX(GPMC_A8, (AM33XX_PIN_INPUT | OMAP_MUX_5 )) /* PR1_MII1_RXD0 */;
	AM33XX_MUX(GPMC_A9, (AM33XX_PIN_INPUT | OMAP_MUX_5 )) /* PR1_MII_MR1_CLK */;
	AM33XX_MUX(GPMC_A10, (AM33XX_PIN_INPUT | OMAP_MUX_5 )) /* PR1_MII1_RXDV */;
	AM33XX_MUX(GPMC_A11, (AM33XX_PIN_INPUT | OMAP_MUX_5 )) /* PR1_MII1_RXER */;
	AM33XX_MUX(GPMC_WAIT0, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_WAIT0 */;
	AM33XX_MUX(GPMC_WPN, (AM33XX_PIN_OUTPUT | OMAP_MUX_5 )) /* PR1_MII1_TXEN */;
	AM33XX_MUX(GPMC_BEN1, (AM33XX_PIN_INPUT | OMAP_MUX_5 )) /* PR1_MII1_RXLINK */;
	AM33XX_MUX(GPMC_CSN0, (AM33XX_PIN_OUTPUT | OMAP_MUX_0 )) /* GPMC_CSN0 */;
	AM33XX_MUX(GPMC_CSN1, (AM33XX_PIN_OUTPUT | OMAP_MUX_0 )) /* GPMC_CSN1 */;
	AM33XX_MUX(GPMC_CSN2, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO1[31] */;
	AM33XX_MUX(GPMC_CSN3, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_5 )) /* PR1_MDIO_DATA */;
	AM33XX_MUX(GPMC_CLK, (AM33XX_PIN_OUTPUT_PULLUP | OMAP_MUX_5 )) /* PR1_MDIO_MDCLK */;
	AM33XX_MUX(GPMC_ADVN_ALE, (AM33XX_PIN_OUTPUT | OMAP_MUX_0 )) /* GPMC_ADVN_ALE */;
	AM33XX_MUX(GPMC_OEN_REN, (AM33XX_PIN_OUTPUT | OMAP_MUX_0 )) /* GPMC_OEN_REN */;
	AM33XX_MUX(GPMC_WEN, (AM33XX_PIN_OUTPUT | OMAP_MUX_0 )) /* GPMC_WEN */;
	AM33XX_MUX(GPMC_BEN0_CLE, (AM33XX_PIN_OUTPUT | OMAP_MUX_7 )) /* GPIO2[5] */;
	AM33XX_MUX(LCD_DATA0, (AM33XX_PIN_INPUT | OMAP_MUX_2 )) /* PR1_MII_MT0_CLK_MUX1 */;
	AM33XX_MUX(LCD_DATA1, (AM33XX_PIN_OUTPUT | OMAP_MUX_2 )) /* PR1_MII0_TXEN_MUX1 */;
	AM33XX_MUX(LCD_DATA2, (AM33XX_PIN_OUTPUT | OMAP_MUX_2 )) /* PR1_MII0_TXD3_MUX1 */;
	AM33XX_MUX(LCD_DATA3, (AM33XX_PIN_OUTPUT | OMAP_MUX_2 )) /* PR1_MII0_TXD2_MUX1 */;
	AM33XX_MUX(LCD_DATA4, (AM33XX_PIN_OUTPUT | OMAP_MUX_2 )) /* PR1_MII0_TXD1_MUX1 */;
	AM33XX_MUX(LCD_DATA5, (AM33XX_PIN_OUTPUT | OMAP_MUX_2 )) /* PR1_MII0_TXD0_MUX1 */;
	AM33XX_MUX(LCD_DATA6, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO2[12] */;
	AM33XX_MUX(LCD_DATA7, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO2[13] */;
	AM33XX_MUX(LCD_DATA8, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO2[14] */;
	AM33XX_MUX(LCD_DATA9, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO2[15] */;
	AM33XX_MUX(LCD_DATA10, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO2[16] */;
	AM33XX_MUX(LCD_DATA11, (AM33XX_PIN_OUTPUT | OMAP_MUX_7 )) /* GPIO2[17] */;
	AM33XX_MUX(LCD_DATA12, (AM33XX_PIN_INPUT | OMAP_MUX_5 )) /* PR1_MII0_RXLINK */;
	AM33XX_MUX(LCD_DATA13, (AM33XX_PIN_INPUT | OMAP_MUX_5 )) /* PR1_MII0_RXER */;
	AM33XX_MUX(LCD_DATA14, (AM33XX_PIN_INPUT | OMAP_MUX_5 )) /* PR1_MII_MR0_CLK */;
	AM33XX_MUX(LCD_DATA15, (AM33XX_PIN_INPUT | OMAP_MUX_5 )) /* PR1_MII0_RXDV */;
	AM33XX_MUX(LCD_VSYNC, (AM33XX_PIN_INPUT | OMAP_MUX_6 )) /* PR1_PRU1_PRU_R31[8] */;
	AM33XX_MUX(LCD_HSYNC, (AM33XX_PIN_INPUT | OMAP_MUX_6 )) /* PR1_PRU1_PRU_R31[9] */;
	AM33XX_MUX(LCD_PCLK, (AM33XX_PIN_INPUT | OMAP_MUX_6 )) /* PR1_PRU1_PRU_R31[10] */;
	AM33XX_MUX(LCD_AC_BIAS_EN, (AM33XX_PIN_INPUT | OMAP_MUX_6 )) /* PR1_PRU1_PRU_R31[11] */;
	AM33XX_MUX(MMC0_DAT3, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO2[26] */;
	AM33XX_MUX(MMC0_DAT2, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO2[27] */;
	AM33XX_MUX(MMC0_DAT1, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO2[28] */;
	AM33XX_MUX(MMC0_DAT0, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO2[29] */;
	AM33XX_MUX(MMC0_CLK, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO2[30] */;
	AM33XX_MUX(MMC0_CMD, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO2[31] */;
	AM33XX_MUX(MII1_COL, (AM33XX_PIN_OUTPUT | OMAP_MUX_7 )) /* GPIO3[0] */;
	AM33XX_MUX(MII1_CRS, (AM33XX_PIN_OUTPUT | OMAP_MUX_7 )) /* GPIO3[1] */;
	AM33XX_MUX(MII1_RX_ER, (AM33XX_PIN_OUTPUT | OMAP_MUX_7 )) /* GPIO3[2] */;
	AM33XX_MUX(MII1_TX_EN, (AM33XX_PIN_OUTPUT | OMAP_MUX_7 )) /* GPIO3[3] */;
	AM33XX_MUX(MII1_RX_DV, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[4] */;
	AM33XX_MUX(MII1_TXD3, (AM33XX_PIN_OUTPUT | OMAP_MUX_7 )) /* GPIO0[16] */;
	AM33XX_MUX(MII1_TXD2, (AM33XX_PIN_OUTPUT | OMAP_MUX_7 )) /* GPIO0[17] */;
	AM33XX_MUX(MII1_TXD1, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO0[21] */;
	AM33XX_MUX(MII1_TXD0, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO0[28] */;
	AM33XX_MUX(MII1_TX_CLK, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[9] */;
	AM33XX_MUX(MII1_RX_CLK, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[10] */;
	AM33XX_MUX(MII1_RXD3, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO2[18] */;
	AM33XX_MUX(MII1_RXD2, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO2[19] */;
	AM33XX_MUX(MII1_RXD1, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO2[20] */;
	AM33XX_MUX(MII1_RXD0, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO2[21] */;
	AM33XX_MUX(RMII1_REF_CLK, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO0[29] */;
	AM33XX_MUX(MDIO, (AM33XX_PIN_OUTPUT | OMAP_MUX_7 )) /* GPIO0[0] */;
	AM33XX_MUX(MDC, (AM33XX_PIN_OUTPUT | OMAP_MUX_7 )) /* GPIO0[1] */;
	AM33XX_MUX(SPI0_SCLK, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* SPI0_SCLK */;
	AM33XX_MUX(SPI0_D0, (AM33XX_PIN_INPUT | OMAP_MUX_0 )) /* SPI0_D0 */;
	AM33XX_MUX(SPI0_D1, (AM33XX_PIN_OUTPUT | OMAP_MUX_0 )) /* SPI0_D1 */;
	AM33XX_MUX(SPI0_CS0, (AM33XX_PIN_OUTPUT | OMAP_MUX_0 )) /* SPI0_CS0 */;
	AM33XX_MUX(SPI0_CS1, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[6] */;
	AM33XX_MUX(ECAP0_IN_PWM0_OUT, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[7] */;
	AM33XX_MUX(UART0_CTSN, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO1[8] */;
	AM33XX_MUX(UART0_RTSN, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO1[9] */;
	AM33XX_MUX(UART0_RXD, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO1[10] */;
	AM33XX_MUX(UART0_TXD, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO1[11] */;
	AM33XX_MUX(UART1_CTSN, (AM33XX_PIN_OUTPUT | OMAP_MUX_7 )) /* GPIO0[12] */;
	AM33XX_MUX(UART1_RTSN, (AM33XX_PIN_OUTPUT | OMAP_MUX_7 )) /* GPIO0[13] */;
	AM33XX_MUX(UART1_RXD, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[14] */;
	AM33XX_MUX(UART1_TXD, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[15] */;
	AM33XX_MUX(I2C0_SDA, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* I2C0_SDA */;
	AM33XX_MUX(I2C0_SCL, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* I2C0_SCL */;
	AM33XX_MUX(MCASP0_ACLKX, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_3 )) /* SPI1_SCLK_MUX2 */;
	AM33XX_MUX(MCASP0_FSX, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_3 )) /* SPI1_D0_MUX2 */;
	AM33XX_MUX(MCASP0_AXR0, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_3 )) /* SPI1_D1_MUX2 */;
	AM33XX_MUX(MCASP0_AHCLKR, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[17] */;
	AM33XX_MUX(MCASP0_ACLKR, (AM33XX_PIN_OUTPUT | OMAP_MUX_7 )) /* GPIO3[18] */;
	AM33XX_MUX(MCASP0_FSR, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[19] */;
	AM33XX_MUX(MCASP0_AXR1, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[20] */;
	AM33XX_MUX(MCASP0_AHCLKX, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[21] */;
	AM33XX_MUX(XDMA_EVENT_INTR0, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[19] */;
	AM33XX_MUX(XDMA_EVENT_INTR1, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[20] */;
	}
	if(mode == GPMC_non_muxed_16bit)
	{
		AM33XX_MUX(GPMC_AD0, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD0 */;
		AM33XX_MUX(GPMC_AD1, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD1 */;
		AM33XX_MUX(GPMC_AD2, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD2 */;
		AM33XX_MUX(GPMC_AD3, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD3 */;
		AM33XX_MUX(GPMC_AD4, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD4 */;
		AM33XX_MUX(GPMC_AD5, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD5 */;
		AM33XX_MUX(GPMC_AD6, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD6 */;
		AM33XX_MUX(GPMC_AD7, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD7 */;
		AM33XX_MUX(GPMC_AD8, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD8 */;
		AM33XX_MUX(GPMC_AD9, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD9 */;
		AM33XX_MUX(GPMC_AD10, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD10 */;
		AM33XX_MUX(GPMC_AD11, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD11 */;
		AM33XX_MUX(GPMC_AD12, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD12 */;
		AM33XX_MUX(GPMC_AD13, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD13 */;
		AM33XX_MUX(GPMC_AD14, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD14 */;
		AM33XX_MUX(GPMC_AD15, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_0 )) /* GPMC_AD15 */;
		AM33XX_MUX(GPMC_A0, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO1[16] */;
		AM33XX_MUX(GPMC_A1, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO1[17] */;
		AM33XX_MUX(GPMC_A2, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO1[18] */;
		AM33XX_MUX(GPMC_A3, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO1[19] */;
		AM33XX_MUX(GPMC_A4, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO1[20] */;
		AM33XX_MUX(GPMC_A5, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO1[21] */;
		AM33XX_MUX(GPMC_A6, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO1[22] */;
		AM33XX_MUX(GPMC_A7, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO1[23] */;
		AM33XX_MUX(GPMC_A8, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO1[24] */;
		AM33XX_MUX(GPMC_A9, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO1[25] */;
		AM33XX_MUX(GPMC_A10, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO1[26] */;
		AM33XX_MUX(GPMC_A11, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO1[27] */;
		AM33XX_MUX(GPMC_WAIT0, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_0 )) /* GPMC_WAIT0 */;
		AM33XX_MUX(GPMC_WPN, (AM33XX_PIN_OUTPUT_PULLUP | OMAP_MUX_0 )) /* GPMC_WPN */;
		AM33XX_MUX(GPMC_BEN1, (AM33XX_PIN_OUTPUT_PULLUP | OMAP_MUX_0 )) /* GPMC_BE1N_MUX0 */;
		AM33XX_MUX(GPMC_CSN0, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO1[29] */;
		AM33XX_MUX(GPMC_CSN1, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_1 )) /* GPMC_CLK_MUX1 */;
		AM33XX_MUX(GPMC_CSN2, (AM33XX_PIN_OUTPUT_PULLUP | OMAP_MUX_0 )) /* GPMC_CSN2 */;
		AM33XX_MUX(GPMC_CSN3, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO2[0] */;
		AM33XX_MUX(GPMC_CLK, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO2[1] */;
		AM33XX_MUX(GPMC_ADVN_ALE, (AM33XX_PIN_OUTPUT_PULLUP | OMAP_MUX_0 )) /* GPMC_ADVN_ALE */;
		AM33XX_MUX(GPMC_OEN_REN, (AM33XX_PIN_OUTPUT_PULLUP | OMAP_MUX_0 )) /* GPMC_OEN_REN */;
		AM33XX_MUX(GPMC_WEN, (AM33XX_PIN_OUTPUT_PULLUP | OMAP_MUX_0 )) /* GPMC_WEN */;
		AM33XX_MUX(GPMC_BEN0_CLE, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO2[5] */;
		AM33XX_MUX(LCD_DATA0, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO2[6] */;
		AM33XX_MUX(LCD_DATA1, (AM33XX_PIN_OUTPUT | OMAP_MUX_1 )) /* GPMC_A1_MUX1 */;
		AM33XX_MUX(LCD_DATA2, (AM33XX_PIN_OUTPUT | OMAP_MUX_1 )) /* GPMC_A2_MUX1 */;
		AM33XX_MUX(LCD_DATA3, (AM33XX_PIN_OUTPUT | OMAP_MUX_1 )) /* GPMC_A3_MUX1 */;
		AM33XX_MUX(LCD_DATA4, (AM33XX_PIN_OUTPUT | OMAP_MUX_1 )) /* GPMC_A4_MUX1 */;
		AM33XX_MUX(LCD_DATA5, (AM33XX_PIN_OUTPUT | OMAP_MUX_1 )) /* GPMC_A5_MUX1 */;
		AM33XX_MUX(LCD_DATA6, (AM33XX_PIN_OUTPUT | OMAP_MUX_1 )) /* GPMC_A6_MUX1 */;
		AM33XX_MUX(LCD_DATA7, (AM33XX_PIN_OUTPUT | OMAP_MUX_1 )) /* GPMC_A7_MUX1 */;
		AM33XX_MUX(LCD_DATA8, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO2[14] */;
		AM33XX_MUX(LCD_DATA9, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO2[15] */;
		AM33XX_MUX(LCD_DATA10, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO2[16] */;
		AM33XX_MUX(LCD_DATA11, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO2[17] */;
		AM33XX_MUX(LCD_DATA12, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[8] */;
		AM33XX_MUX(LCD_DATA13, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[9] */;
		AM33XX_MUX(LCD_DATA14, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[10] */;
		AM33XX_MUX(LCD_DATA15, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[11] */;
		AM33XX_MUX(LCD_VSYNC, (AM33XX_PIN_OUTPUT | OMAP_MUX_1 )) /* GPMC_A8_MUX1 */;
		AM33XX_MUX(LCD_HSYNC, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO2[23] */;
		AM33XX_MUX(LCD_PCLK, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO2[24] */;
		AM33XX_MUX(LCD_AC_BIAS_EN, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO2[25] */;
		AM33XX_MUX(MMC0_DAT3, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO2[26] */;
		AM33XX_MUX(MMC0_DAT2, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO2[27] */;
		AM33XX_MUX(MMC0_DAT1, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO2[28] */;
		AM33XX_MUX(MMC0_DAT0, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO2[29] */;
		AM33XX_MUX(MMC0_CLK, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO2[30] */;
		AM33XX_MUX(MMC0_CMD, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO2[31] */;
		AM33XX_MUX(MII1_COL, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[0] */;
		AM33XX_MUX(MII1_CRS, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[1] */;
		AM33XX_MUX(MII1_RX_ER, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[2] */;
		AM33XX_MUX(MII1_TX_EN, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[3] */;
		AM33XX_MUX(MII1_RX_DV, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[4] */;
		AM33XX_MUX(MII1_TXD3, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO0[16] */;
		AM33XX_MUX(MII1_TXD2, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO0[17] */;
		AM33XX_MUX(MII1_TXD1, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO0[21] */;
		AM33XX_MUX(MII1_TXD0, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO0[28] */;
		AM33XX_MUX(MII1_TX_CLK, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[9] */;
		AM33XX_MUX(MII1_RX_CLK, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[10] */;
		AM33XX_MUX(MII1_RXD3, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO2[18] */;
		AM33XX_MUX(MII1_RXD2, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO2[19] */;
		AM33XX_MUX(MII1_RXD1, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO2[20] */;
		AM33XX_MUX(MII1_RXD0, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO2[21] */;
		AM33XX_MUX(RMII1_REF_CLK, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO0[29] */;
		AM33XX_MUX(MDIO, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO0[0] */;
		AM33XX_MUX(MDC, (AM33XX_PIN_INPUT_PULLUP | OMAP_MUX_7 )) /* GPIO0[1] */;
		AM33XX_MUX(SPI0_SCLK, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[2] */;
		AM33XX_MUX(SPI0_D0, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[3] */;
		AM33XX_MUX(SPI0_D1, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[4] */;
		AM33XX_MUX(SPI0_CS0, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[5] */;
		AM33XX_MUX(SPI0_CS1, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[6] */;
		AM33XX_MUX(ECAP0_IN_PWM0_OUT, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[7] */;
		AM33XX_MUX(UART0_CTSN, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO1[8] */;
		AM33XX_MUX(UART0_RTSN, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO1[9] */;
		AM33XX_MUX(UART0_RXD, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO1[10] */;
		AM33XX_MUX(UART0_TXD, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO1[11] */;
		AM33XX_MUX(UART1_CTSN, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[12] */;
		AM33XX_MUX(UART1_RTSN, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[13] */;
		AM33XX_MUX(UART1_RXD, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[14] */;
		AM33XX_MUX(UART1_TXD, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[15] */;
		AM33XX_MUX(I2C0_SDA, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO3[5] */;
		AM33XX_MUX(I2C0_SCL, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO3[6] */;
		AM33XX_MUX(MCASP0_ACLKX, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[14] */;
		AM33XX_MUX(MCASP0_FSX, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[15] */;
		AM33XX_MUX(MCASP0_AXR0, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[16] */;
		AM33XX_MUX(MCASP0_AHCLKR, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[17] */;
		AM33XX_MUX(MCASP0_ACLKR, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[18] */;
		AM33XX_MUX(MCASP0_FSR, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[19] */;
		AM33XX_MUX(MCASP0_AXR1, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[20] */;
		AM33XX_MUX(MCASP0_AHCLKX, (AM33XX_PIN_INPUT_PULLDOWN | OMAP_MUX_7 )) /* GPIO3[21] */;
		AM33XX_MUX(XDMA_EVENT_INTR0, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[19] */;
		AM33XX_MUX(XDMA_EVENT_INTR1, (AM33XX_PIN_INPUT | OMAP_MUX_7 )) /* GPIO0[20] */;
	}
}