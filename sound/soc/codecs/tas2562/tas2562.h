
#ifndef __TAS2562_
#define __TAS2562_

#define TAS2562_DRIVER_ID           "2.1.0"

/* Page Control Register */
#define TAS2562_PAGECTL_REG			0

/* Book Control Register (available in page0 of each book) */
#define TAS2562_BOOKCTL_PAGE		0
#define TAS2562_BOOKCTL_REG			127

#define TAS2562_REG(book, page, reg)	(((book * 256 * 128) + \
					(page * 128)) + reg)

#define TAS2562_BOOK_ID(reg)			(reg / (256 * 128))

#define TAS2562_PAGE_ID(reg)			((reg % (256 * 128)) / 128)

#define TAS2562_BOOK_REG(reg)			(reg % (256 * 128))

#define TAS2562_PAGE_REG(reg)			((reg % (256 * 128)) % 128)

/* Added for register cache table */
#define MAX_REGISTERS		0x7f

    /* Software Reset */
#define TAS2562_SOFTWARERESET  TAS2562_REG(0x0, 0x0, 0x01)
#define TAS2562_SOFTWARERESET_SOFTWARERESET_MASK  (0x1 << 0),
#define TAS2562_SOFTWARERESET_SOFTWARERESET_DONTRESET  (0x0 << 0)
#define TAS2562_SOFTWARERESET_SOFTWARERESET_RESET  (0x1 << 0)

    /* Power Control */
#define TAS2562_POWERCONTROL  TAS2562_REG(0x0, 0x0, 0x02)
#define TAS2562_POWERCONTROL_ISNSPOWER_MASK  (0x1 << 3)
#define TAS2562_POWERCONTROL_ISNSPOWER_ACTIVE  (0x0 << 3)
#define TAS2562_POWERCONTROL_ISNSPOWER_POWEREDDOWN  (0x1 << 3)
#define TAS2562_POWERCONTROL_VSNSPOWER_MASK  (0x1 << 2)
#define TAS2562_POWERCONTROL_VSNSPOWER_ACTIVE  (0x0 << 2)
#define TAS2562_POWERCONTROL_VSNSPOWER_POWEREDDOWN  (0x1 << 2)
#define TAS2562_POWERCONTROL_OPERATIONALMODE10_MASK  (0x3 << 0)
#define TAS2562_POWERCONTROL_OPERATIONALMODE10_ACTIVE  (0x0 << 0)
#define TAS2562_POWERCONTROL_OPERATIONALMODE10_MUTE  (0x1 << 0)
#define TAS2562_POWERCONTROL_OPERATIONALMODE10_SHUTDOWN  (0x2 << 0)

	/* data format */
#define TAS2562_DATAFORMAT_SHIFT		2
#define TAS2562_DATAFORMAT_I2S			0x0
#define TAS2562_DATAFORMAT_DSP			0x1
#define TAS2562_DATAFORMAT_RIGHT_J		0x2
#define TAS2562_DATAFORMAT_LEFT_J		0x3

#define TAS2562_DAI_FMT_MASK		(0x7 << TAS2562_DATAFORMAT_SHIFT)

    /* Playback Configuration Reg0 */
#define TAS2562_PLAYBACKCONFIGURATIONREG0  TAS2562_REG(0x0, 0x0, 0x03)
#define TAS2562_PLAYBACKCONFIGURATIONREG0_DCBLOCKER_MASK  (0x1 << 6)
#define TAS2562_PLAYBACKCONFIGURATIONREG0_DCBLOCKER_ENABLED  (0x0 << 6)
#define TAS2562_PLAYBACKCONFIGURATIONREG0_DCBLOCKER_DISABLED  (0x1 << 6)
#define TAS2562_PLAYBACKCONFIGURATIONREG0_AMPLIFIERLEVEL51_MASK  (0x1f << 1)

    /* Misc Configuration Reg0 */
#define TAS2562_MISCCONFIGURATIONREG0  TAS2562_REG(0x0, 0x0, 0x04)
#define TAS2562_MISCCONFIGURATIONREG0_CPPGRETRY_MASK  (0x1 << 7)
#define TAS2562_MISCCONFIGURATIONREG0_CPPGRETRY_DONOTRETRY  (0x0 << 7)
#define TAS2562_MISCCONFIGURATIONREG0_CPPGRETRY_RETRY  (0x1 << 7)
#define TAS2562_MISCCONFIGURATIONREG0_VBATPRORETRY_MASK  (0x1 << 6)
#define TAS2562_MISCCONFIGURATIONREG0_VBATPRORETRY_DONOTRETRY  (0x0 << 6)
#define TAS2562_MISCCONFIGURATIONREG0_VBATPRORETRY_RETRY  (0x1 << 6)
#define TAS2562_MISCCONFIGURATIONREG0_OCERETRY_MASK  (0x1 << 5)
#define TAS2562_MISCCONFIGURATIONREG0_OCERETRY_DONOTRETRY  (0x0 << 5)
#define TAS2562_MISCCONFIGURATIONREG0_OCERETRY_RETRY  (0x1 << 5)
#define TAS2562_MISCCONFIGURATIONREG0_OTERETRY_MASK  (0x1 << 4)
#define TAS2562_MISCCONFIGURATIONREG0_OTERETRY_DONOTRETRY  (0x0 << 4)
#define TAS2562_MISCCONFIGURATIONREG0_OTERETRY_RETRY  (0x1 << 4)
#define TAS2562_MISCCONFIGURATIONREG0_IRQZPULL_MASK  (0x1 << 3)
#define TAS2562_MISCCONFIGURATIONREG0_IRQZPULL_DISABLED  (0x0 << 3)
#define TAS2562_MISCCONFIGURATIONREG0_IRQZPULL_ENABLED  (0x1 << 3)
#define TAS2562_MISCCONFIGURATIONREG0_AMPSS_MASK  (0x1 << 2)
#define TAS2562_MISCCONFIGURATIONREG0_AMPSS_DISABLED  (0x0 << 2)
#define TAS2562_MISCCONFIGURATIONREG0_AMPSS_ENABLED  (0x1 << 2)

    /* TDM Configuration Reg0 */
#define TAS2562_TDMCONFIGURATIONREG0  TAS2562_REG(0x0, 0x0, 0x06)
#define TAS2562_TDMCONFIGURATIONREG0_SAMPRATERAMP_MASK  (0x1 << 5)
#define TAS2562_TDMCONFIGURATIONREG0_SAMPRATERAMP_48KHZ  (0x0 << 5)
#define TAS2562_TDMCONFIGURATIONREG0_SAMPRATERAMP_44_1KHZ  (0x1 << 5)
#define TAS2562_TDMCONFIGURATIONREG0_DETECTSAMPRATE_MASK  (0x1 << 4)
#define TAS2562_TDMCONFIGURATIONREG0_DETECTSAMPRATE_DISABLED  (0x1 << 4)
#define TAS2562_TDMCONFIGURATIONREG0_DETECTSAMPRATE_ENABLED  (0x0 << 4)
#define TAS2562_TDMCONFIGURATIONREG0_SAMPRATE31_MASK  (0x7 << 1)
#define TAS2562_TDMCONFIGURATIONREG0_SAMPRATE31_14_7_16KHZ  (0x1 << 1)
#define TAS2562_TDMCONFIGURATIONREG0_SAMPRATE31_44_1_48KHZ  (0x4 << 1)
#define TAS2562_TDMCONFIGURATIONREG0_SAMPRATE31_88_2_96KHZ  (0x5 << 1)
#define TAS2562_TDMCONFIGURATIONREG0_SAMPRATE31_176_4_192KHZ  (0x6 << 1)
#define TAS2562_TDMCONFIGURATIONREG0_FRAMESTART_MASK  (0x1 << 0)
#define TAS2562_TDMCONFIGURATIONREG0_FRAMESTART_LOWTOHIGH  (0x0 << 0)
#define TAS2562_TDMCONFIGURATIONREG0_FRAMESTART_HIGHTOLOW  (0x1 << 0)

    /* TDM Configuration Reg1 */
#define TAS2562_TDMCONFIGURATIONREG1  TAS2562_REG(0x0, 0x0, 0x07)
#define TAS2562_TDMCONFIGURATIONREG1_RXJUSTIFY_MASK  (0x1 << 6)
#define TAS2562_TDMCONFIGURATIONREG1_RXJUSTIFY_LEFT  (0x0 << 6)
#define TAS2562_TDMCONFIGURATIONREG1_RXJUSTIFY_RIGHT  (0x1 << 6)
#define TAS2562_TDMCONFIGURATIONREG1_RXOFFSET51_MASK  (0x1f << 1)
#define TAS2562_TDMCONFIGURATIONREG1_RXOFFSET51_SHIFT (1)
#define TAS2562_TDMCONFIGURATIONREG1_RXEDGE_MASK  (0x1 << 0)
#define TAS2562_TDMCONFIGURATIONREG1_RXEDGE_RISING  (0x0 << 0)
#define TAS2562_TDMCONFIGURATIONREG1_RXEDGE_FALLING  (0x1 << 0)

    /* TDM Configuration Reg2 */
#define TAS2562_TDMCONFIGURATIONREG2  TAS2562_REG(0x0, 0x0, 0x08)
#define TAS2562_TDMCONFIGURATIONREG2_IVMONLEN76_MASK  (0x3 << 6)
#define TAS2562_TDMCONFIGURATIONREG2_IVMONLEN76_8BITS  (0x2 << 6)
#define TAS2562_TDMCONFIGURATIONREG2_IVMONLEN76_12BITS  (0x1 << 6)
#define TAS2562_TDMCONFIGURATIONREG2_IVMONLEN76_16BITS  (0x0 << 6)
#define TAS2562_TDMCONFIGURATIONREG2_RXSCFG54_MASK  (0x3 << 4)
#define TAS2562_TDMCONFIGURATIONREG2_RXSCFG54_MONO_I2C  (0x0 << 4)
#define TAS2562_TDMCONFIGURATIONREG2_RXSCFG54_MONO_LEFT  (0x1 << 4)
#define TAS2562_TDMCONFIGURATIONREG2_RXSCFG54_MONO_RIGHT  (0x2 << 4)
#define TAS2562_TDMCONFIGURATIONREG2_RXSCFG54_STEREO_DOWNMIX  (0x3 << 4)
#define TAS2562_TDMCONFIGURATIONREG2_RXWLEN32_MASK  (0x3 << 2)
#define TAS2562_TDMCONFIGURATIONREG2_RXWLEN32_16BITS  (0x0 << 2)
#define TAS2562_TDMCONFIGURATIONREG2_RXWLEN32_20BITS  (0x1 << 2)
#define TAS2562_TDMCONFIGURATIONREG2_RXWLEN32_24BITS  (0x2 << 2)
#define TAS2562_TDMCONFIGURATIONREG2_RXWLEN32_32BITS  (0x3 << 2)
#define TAS2562_TDMCONFIGURATIONREG2_RXSLEN10_MASK  (0x3 << 0)
#define TAS2562_TDMCONFIGURATIONREG2_RXSLEN10_16BITS  (0x0 << 0)
#define TAS2562_TDMCONFIGURATIONREG2_RXSLEN10_24BITS  (0x1 << 0)
#define TAS2562_TDMCONFIGURATIONREG2_RXSLEN10_32BITS  (0x2 << 0)

    /* TDM Configuration Reg3 */
#define TAS2562_TDMCONFIGURATIONREG3  TAS2562_REG(0x0, 0x0, 0x09)
#define TAS2562_TDMCONFIGURATIONREG3_RXSLOTRIGHT74_MASK  (0xf << 4)
#define TAS2562_TDMCONFIGURATIONREG3_RXSLOTLeft30_Mask  (0xf << 0)

    /* TDM Configuration Reg4 */
#define TAS2562_TDMConfigurationReg4  TAS2562_REG(0x0, 0x0, 0x0A)
#define TAS2562_TDMCONFIGURATIONREG4_TXKEEPER_MASK  (0x1 << 5)
#define TAS2562_TDMCONFIGURATIONREG4_TXKEEPER_DISABLE  (0x0 << 5)
#define TAS2562_TDMCONFIGURATIONREG4_TXKEEPER_ENABLE  (0x1 << 5)
#define TAS2562_TDMCONFIGURATIONREG4_TXFILL_MASK  (0x1 << 4)
#define TAS2562_TDMCONFIGURATIONREG4_TXFILL_TRANSMIT0  (0x0 << 4)
#define TAS2562_TDMCONFIGURATIONREG4_TXFILL_TRANSMITHIZ  (0x1 << 4)
#define TAS2562_TDMCONFIGURATIONREG4_TXOFFSET31_MASK  (0x7 << 1)
#define TAS2562_TDMCONFIGURATIONREG4_TXEDGE_MASK  (0x1 << 0)
#define TAS2562_TDMCONFIGURATIONREG4_TXEDGE_RISING  (0x0 << 0)
#define TAS2562_TDMCONFIGURATIONREG4_TXEDGE_FALLING  (0x1 << 0)

    /* TDM Configuration Reg5 */
#define TAS2562_TDMCONFIGURATIONREG5  TAS2562_REG(0x0, 0x0, 0x0B)
#define TAS2562_TDMCONFIGURATIONREG5_VSNSTX_MASK  (0x1 << 6)
#define TAS2562_TDMCONFIGURATIONREG5_VSNSTX_DISABLE  (0x0 << 6),
#define TAS2562_TDMCONFIGURATIONREG5_VSNSTX_ENABLE  (0x1 << 6),
#define TAS2562_TDMCONFIGURATIONREG5_VSNSSLOT50_MASK  (0x3f << 0)

    /* TDM Configuration Reg6 */
#define TAS2562_TDMCONFIGURATIONREG6  TAS2562_REG(0x0, 0x0, 0x0C)
#define TAS2562_TDMCONFIGURATIONREG6_ISNSTX_MASK  (0x1 << 6)
#define TAS2562_TDMCONFIGURATIONREG6_ISNSTX_DISABLE  (0x0 << 6),
#define TAS2562_TDMCONFIGURATIONREG6_ISNSTX_ENABLE  (0x1 << 6),
#define TAS2562_TDMCONFIGURATIONREG6_ISNSSLOT50_MASK  (0x3f << 0)

    /* TDM Configuration Reg7 */
#define TAS2562_TDMCONFIGURATIONREG7  TAS2562_REG(0x0, 0x0, 0x0D)
#define TAS2562_TDMCONFIGURATIONREG7_VBATSLEN_MASK  (0x1 << 7)
#define TAS2562_TDMCONFIGURATIONREG7_VBATSLEN_8BITS  (0x0 << 7)
#define TAS2562_TDMCONFIGURATIONREG7_VBATSLEN_16BITS  (0x1 << 7)
#define TAS2562_TDMCONFIGURATIONREG7_VBATTX_MASK  (0x1 << 6)
#define TAS2562_TDMCONFIGURATIONREG7_VBATTX_DISABLE  (0x0 << 6)
#define TAS2562_TDMCONFIGURATIONREG7_VBATTX_ENABLE  (0x1 << 6)
#define TAS2562_TDMCONFIGURATIONREG7_VBATSLOT50_MASK  (0x3f << 0)

    /* TDM Configuration Reg8 */
#define TAS2562_TDMCONFIGURATIONREG8  TAS2562_REG(0x0, 0x0, 0x0E)
#define TAS2562_TDMCONFIGURATIONREG8_TEMPTX_MASK  (0x1 << 6)
#define TAS2562_TDMCONFIGURATIONREG8_TEMPTX_DISABLE  (0x0 << 6)
#define TAS2562_TDMCONFIGURATIONREG8_TEMPTX_ENABLE  (0x1 << 6)
#define TAS2562_TDMCONFIGURATIONREG8_TEMPSLOT50_MASK  (0x3f << 0)

    /* TDM Configuration Reg9 */
#define TAS2562_TDMCONFIGURATIONREG9  TAS2562_REG(0x0, 0x0, 0x0F)
#define TAS2562_TDMCONFIGURATIONREG9_GAINTX_MASK  (0x1 << 6)
#define TAS2562_TDMCONFIGURATIONREG9_GAINTX_DISABLE  (0x0 << 6)
#define TAS2562_TDMCONFIGURATIONREG9_GAINTX_ENABLE  (0x1 << 6)
#define TAS2562_TDMCONFIGURATIONREG9_GAINSLOT50_MASK  (0x3f << 0)

    /* Limiter Configuration Reg0 */
#define TAS2562_LIMITERCONFIGURATIONREG0  TAS2562_REG(0x0, 0x0, 0x12)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMATKST54_MASK  (0x3 << 4)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMATKST54_1  (0x2 << 4)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMATKST54_2  (0x3 << 4)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMATKST54_0_25  (0x0 << 4)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMATKST54_0_5  (0x1 << 4)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMATKRT31_MASK  (0x7 << 1)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMATKRT31_5  (0x0 << 1)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMATKRT31_10  (0x1 << 1)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMATKRT31_20  (0x2 << 1)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMATKRT31_40  (0x3 << 1)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMATKRT31_80  (0x4 << 1)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMATKRT31_160  (0x5 << 1)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMATKRT31_320  (0x6 << 1)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMATKRT31_640  (0x7 << 1)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMEN_MASK  (0x1 << 0)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMEN_DISABLED  (0x0 << 0)
#define TAS2562_LIMITERCONFIGURATIONREG0_LIMEN_ENABLED  (0x1 << 0)

    /* Limiter Configuration Reg1 */
#define TAS2562_LIMITERCONFIGURATIONREG1  TAS2562_REG(0x0, 0x0, 0x13)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMRLSST76_MASK  (0x3 << 6)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMRLSST76_1  (0x2 << 6)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMRLSST76_2  (0x3 << 6)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMRLSST76_0_25  (0x0 << 6)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMRLSST76_0_5  (0x1 << 6)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMRLSRT53_MASK  (0x7 << 3)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMRLSRT53_10  (0x0 << 3)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMRLSRT53_50  (0x1 << 3)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMRLSRT53_100  (0x2 << 3)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMRLSRT53_250  (0x3 << 3)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMRLSRT53_500  (0x4 << 3)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMRLSRT53_750  (0x5 << 3)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMRLSRT53_1000  (0x6 << 3)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMRLSRT53_1500  (0x7 << 3)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMHLDTM20_MASK  (0x7 << 0)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMHLDTM20_0  (0x0 << 0)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMHLDTM20_10  (0x1 << 0)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMHLDTM20_25  (0x2 << 0)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMHLDTM20_50  (0x3 << 0)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMHLDTM20_100  (0x4 << 0)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMHLDTM20_250  (0x5 << 0)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMHLDTM20_500  (0x6 << 0)
#define TAS2562_LIMITERCONFIGURATIONREG1_LIMHLDTM20_1000  (0x7 << 0)

    /* Brown Out Prevention Reg0 */
#define TAS2562_BROWNOUTPREVENTIONREG0  TAS2562_REG(0x0, 0x0, 0x14)
#define TAS2562_BROWNOUTPREVENTIONREG0_BOPSDEN_MASK  (0x1 << 4)
#define TAS2562_BROWNOUTPREVENTIONREG0_BOPSDEN_DISABLED  (0x0 << 4)
#define TAS2562_BROWNOUTPREVENTIONREG0_BOPSDEN_ENABLED  (0x1 << 4)
#define TAS2562_BROWNOUTPREVENTIONREG0_BOPHLDCLR_MASK  (0x1 << 3)
#define TAS2562_BROWNOUTPREVENTIONREG0_BOPHLDCLR_DONTCLEAR  (0x0 << 3)
#define TAS2562_BROWNOUTPREVENTIONREG0_BOPHLDCLR_CLEAR  (0x1 << 3)
#define TAS2562_BROWNOUTPREVENTIONREG0_BOPINFHLD_MASK  (0x1 << 2)
#define TAS2562_BROWNOUTPREVENTIONREG0_BOPINFHLD_USEHOLDTIME  (0x0 << 2)
#define TAS2562_BROWNOUTPREVENTIONREG0_BOPINFHLD_HOLDUNTILCLEARED  (0x1 << 2)
#define TAS2562_BROWNOUTPREVENTIONREG0_BOPMUTE_MASK  (0x1 << 1)
#define TAS2562_BROWNOUTPREVENTIONREG0_BOPMUTE_DONOTMUTE  (0x0 << 1)
#define TAS2562_BROWNOUTPREVENTIONREG0_BOPMUTE_MUTE  (0x1 << 1)
#define TAS2562_BROWNOUTPREVENTIONREG0_BOPEN_MASK  (0x1 << 0)
#define TAS2562_BROWNOUTPREVENTIONREG0_BOPEN_DISABLED  (0x0 << 0)
#define TAS2562_BROWNOUTPREVENTIONREG0_BOPEN_ENABLED  (0x1 << 0)

    /* Brown Out Prevention Reg1 */
#define TAS2562_BROWNOUTPREVENTIONREG1  TAS2562_REG(0x0, 0x0, 0x15)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPATKRT75_MASK  (0x7 << 5)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPATKRT75_1  (0x0 << 5)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPATKRT75_2  (0x1 << 5)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPATKRT75_4  (0x2 << 5)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPATKRT75_8  (0x3 << 5)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPATKRT75_16  (0x4 << 5)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPATKRT75_32  (0x5 << 5)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPATKRT75_64  (0x6 << 5)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPATKRT75_128  (0x7 << 5)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPATKST43_MASK  (0x3 << 3)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPATKST43_1  (0x1 << 3)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPATKST43_2  (0x3 << 3)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPATKST43_0_5  (0x0 << 3)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPATKST43_1_5  (0x2 << 3)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPHLDTM20_MASK  (0x7 << 0)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPHLDTM20_0  (0x0 << 0)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPHLDTM20_10  (0x1 << 0)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPHLDTM20_25  (0x2 << 0)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPHLDTM20_50  (0x3 << 0)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPHLDTM20_100  (0x4 << 0)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPHLDTM20_250  (0x5 << 0)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPHLDTM20_500  (0x6 << 0)
#define TAS2562_BROWNOUTPREVENTIONREG1_BOPHLDTM20_1000  (0x7 << 0)

/* Interrupt Mask Reg0 */
#define TAS2562_INTERRUPTMASKREG0  TAS2562_REG(0x0, 0x0, 0x1A)
#define TAS2562_INTERRUPTMASKREG0_LIMMUTEINTMASK_MASK  (0x1 << 7)
#define TAS2562_INTERRUPTMASKREG0_LIMMUTEINTMASK_UNMASK  (0x0 << 7)
#define TAS2562_INTERRUPTMASKREG0_LIMMUTEINTMASK_DISABLE  (0x1 << 7)
#define TAS2562_INTERRUPTMASKREG0_LIMINFHLDINTMASK_MASK  (0x1 << 6)
#define TAS2562_INTERRUPTMASKREG0_LIMINFHLDINTMASK_UNMASK  (0x0 << 6)
#define TAS2562_INTERRUPTMASKREG0_LIMINFHLDINTMASK_DISABLE  (0x1 << 6)
#define TAS2562_INTERRUPTMASKREG0_LIMMAXATNINTMASK_MASK  (0x1 << 5)
#define TAS2562_INTERRUPTMASKREG0_LIMMAXATNINTMASK_UNMASK  (0x0 << 5)
#define TAS2562_INTERRUPTMASKREG0_LIMMAXATNINTMASK_DISABLE  (0x1 << 5)
#define TAS2562_INTERRUPTMASKREG0_VBATLESSTHANINFINTMASK_MASK  (0x1 << 4)
#define TAS2562_INTERRUPTMASKREG0_VBATLESSTHANINFINTMASK_UNMASK  (0x0 << 4)
#define TAS2562_INTERRUPTMASKREG0_VBATLESSTHANINFINTMASK_DISABLE  (0x1 << 4)
#define TAS2562_INTERRUPTMASKREG0_LIMACTIVEFLAGINTMASK_MASK  (0x1 << 3)
#define TAS2562_INTERRUPTMASKREG0_LIMACTIVEFLAGINTMASK_UNMASK  (0x0 << 3)
#define TAS2562_INTERRUPTMASKREG0_LIMACTIVEFLAGINTMASK_DISABLE  (0x1 << 3)
#define TAS2562_INTERRUPTMASKREG0_TDMCLOCKERRORINTMASK_MASK  (0x1 << 2)
#define TAS2562_INTERRUPTMASKREG0_TDMCLOCKERRORINTMASK_UNMASK  (0x0 << 2)
#define TAS2562_INTERRUPTMASKREG0_TDMCLOCKERRORINTMASK_DISABLE  (0x1 << 2)
#define TAS2562_INTERRUPTMASKREG0_OCEINTMASK_MASK  (0x1 << 1)
#define TAS2562_INTERRUPTMASKREG0_OCEINTMASK_UNMASK  (0x0 << 1)
#define TAS2562_INTERRUPTMASKREG0_OCEINTMASK_DISABLE  (0x1 << 1)
#define TAS2562_INTERRUPTMASKREG0_OTEINTMASK_MASK  (0x1 << 0)
#define TAS2562_INTERRUPTMASKREG0_OTEINTMASK_UNMASK  (0x0 << 0)
#define TAS2562_INTERRUPTMASKREG0_OTEINTMASK_DISABLE  (0x1 << 0)
#define TAS2562_INTERRUPTMASKREG0_DISABLE 0xff

    /* Interrupt Mask Reg1 */
#define TAS2562_INTERRUPTMASKREG1  TAS2562_REG(0x0, 0x0, 0x1B)
#define TAS2562_INTERRUPTMASKREG1_DSPOUTPUTINTMASK_MASK  (0x1 << 7)
#define TAS2562_INTERRUPTMASKREG1_DSPOUTPUTINTMASK_UNMASK  (0x0 << 7)
#define TAS2562_INTERRUPTMASKREG1_DSPOUTPUTINTMASK_DISABLE  (0x1 << 7)
#define TAS2562_INTERRUPTMASKREG1_CRCINTMASK_MASK  (0x1 << 6)
#define TAS2562_INTERRUPTMASKREG1_CRCINTMASK_UNMASK  (0x0 << 6)
#define TAS2562_INTERRUPTMASKREG1_CRCINTMASK_DISABLE  (0x1 << 6)
#define TAS2562_INTERRUPTMASKREG1_VBATOVLOINTMASK_MASK  (0x1 << 2)
#define TAS2562_INTERRUPTMASKREG1_VBATOVLOINTMASK_UNMASK  (0x0 << 2)
#define TAS2562_INTERRUPTMASKREG1_VBATOVLOINTMASK_DISABLE  (0x1 << 2)
#define TAS2562_INTERRUPTMASKREG1_VBATUVLOINTMASK_MASK  (0x1 << 1)
#define TAS2562_INTERRUPTMASKREG1_VBATUVLOINTMASK_UNMASK  (0x0 << 1)
#define TAS2562_INTERRUPTMASKREG1_VBATUVLOINTMASK_DISABLE  (0x1 << 1)
#define TAS2562_INTERRUPTMASKREG1_BROWNOUTFLAGINTMASK_MASK  (0x1 << 0)
#define TAS2562_INTERRUPTMASKREG1_BROWNOUTFLAGINTMASK_UNMASK  (0x0 << 0)
#define TAS2562_INTERRUPTMASKREG1_BROWNOUTFLAGINTMASK_DISABLE  (0x1 << 0)
#define TAS2562_INTERRUPTMASKREG1_DISABLE 0xff

    /* Interrupt Mask Reg2 */
#define TAS2562_INTERRUPTMASKREG2  TAS2562_REG(0x0, 0x0, 0x1C)
#define TAS2562_INTERRUPTMASKREG2_DACLKINTMASK_MASK  (0x1 << 7)
#define TAS2562_INTERRUPTMASKREG2_DACLKINTMASK_UNMASK  (0x0 << 7)
#define TAS2562_INTERRUPTMASKREG2_DACLKINTMASK_DISABLE  (0x1 << 7)
#define TAS2562_INTERRUPTMASKREG2_BSTCLKINTMASK_MASK  (0x1 << 6)
#define TAS2562_INTERRUPTMASKREG2_BSTCLKINTMASK_UNMASK  (0x0 << 6)
#define TAS2562_INTERRUPTMASKREG2_BSTCLKINTMASK_DISABLE  (0x1 << 6)
#define TAS2562_INTERRUPTMASKREG2_VBATPORCLKINTMASK_MASK  (0x1 << 5)
#define TAS2562_INTERRUPTMASKREG2_VBATPORCLKINTMASK_UNMASK  (0x0 << 5)
#define TAS2562_INTERRUPTMASKREG2_VBATPORCLKINTMASK_DISABLE  (0x1 << 5)
#define TAS2562_INTERRUPTMASKREG2_PLLOCKINTMASK_MASK  (0x1 << 4)
#define TAS2562_INTERRUPTMASKREG2_PLLOCKINTMASK_UNMASK  (0x0 << 4)
#define TAS2562_INTERRUPTMASKREG2_PLLOCKINTMASK_DISABLE  (0x1 << 4)
#define TAS2562_INTERRUPTMASKREG2_DCDETECTINTMASK_MASK  (0x1 << 3)
#define TAS2562_INTERRUPTMASKREG2_DCDETECTINTMASK_UNMASK  (0x0 << 3)
#define TAS2562_INTERRUPTMASKREG2_DCDETECTINTMASK_DISABLE  (0x1 << 3)

    /* Live-Interrupt Reg0 */
#define TAS2562_LIVEINTERRUPTREG0  TAS2562_REG(0x0, 0x0, 0x1F)
#define TAS2562_LIVEINTERRUPTREG0_LIMMUTE_MASK  (0x1 << 7)
#define TAS2562_LIVEINTERRUPTREG0_LIMMUTE_NOINTERRUPT  (0x0 << 7)
#define TAS2562_LIVEINTERRUPTREG0_LIMMUTE_INTERRUPT  (0x1 << 7)
#define TAS2562_LIVEINTERRUPTREG0_LIMINFHLD_MASK  (0x1 << 6)
#define TAS2562_LIVEINTERRUPTREG0_LIMINFHLD_NOINTERRUPT  (0x0 << 6)
#define TAS2562_LIVEINTERRUPTREG0_LIMINFHLD_INTERRUPT  (0x1 << 6)
#define TAS2562_LIVEINTERRUPTREG0_LIMMAXATN_MASK  (0x1 << 5)
#define TAS2562_LIVEINTERRUPTREG0_LIMMAXATN_NOINTERRUPT  (0x0 << 5)
#define TAS2562_LIVEINTERRUPTREG0_LIMMAXATN_INTERRUPT  (0x1 << 5)
#define TAS2562_LIVEINTERRUPTREG0_VBATLESSTHANINF_MASK  (0x1 << 4)
#define TAS2562_LIVEINTERRUPTREG0_VBATLESSTHANINF_NOINTERRUPT  (0x0 << 4)
#define TAS2562_LIVEINTERRUPTREG0_VBATLESSTHANINF_INTERRUPT  (0x1 << 4)
#define TAS2562_LIVEINTERRUPTREG0_LIMACTIVEFLAG_MASK  (0x1 << 3)
#define TAS2562_LIVEINTERRUPTREG0_LIMACTIVEFLAG_NOINTERRUPT  (0x0 << 3)
#define TAS2562_LIVEINTERRUPTREG0_LIMACTIVEFLAG_INTERRUPT  (0x1 << 3)
#define TAS2562_LIVEINTERRUPTREG0_TDMCLOCKERROR_MASK  (0x1 << 2)
#define TAS2562_LIVEINTERRUPTREG0_TDMCLOCKERROR_NOINTERRUPT  (0x0 << 2)
#define TAS2562_LIVEINTERRUPTREG0_TDMCLOCKERROR_INTERRUPT  (0x1 << 2)
#define TAS2562_LIVEINTERRUPTREG0_OCEFLAG_MASK  (0x1 << 1)
#define TAS2562_LIVEINTERRUPTREG0_OCEFLAG_NOINTERRUPT  (0x0 << 1)
#define TAS2562_LIVEINTERRUPTREG0_OCEFLAG_INTERRUPT  (0x1 << 1)
#define TAS2562_LIVEINTERRUPTREG0_OTEFLAG_MASK  (0x1 << 0)
#define TAS2562_LIVEINTERRUPTREG0_OTEFLAG_NOINTERRUPT  (0x0 << 0)
#define TAS2562_LIVEINTERRUPTREG0_OTEFLAG_INTERRUPT  (0x1 << 0)

    /* Live-Interrupt Reg1 */
#define TAS2562_LIVEINTERRUPTREG1  TAS2562_REG(0x0, 0x0, 0x20)
#define TAS2562_LIVEINTERRUPTREG1_DSPINTOUTPUT_MASK  (0x1 << 7)
#define TAS2562_LIVEINTERRUPTREG1_DSPINTOUTPUT_NOINTERRUPT  (0x0 << 7)
#define TAS2562_LIVEINTERRUPTREG1_DSPINTOUTPUT_INTERRUPT  (0x1 << 7)
#define TAS2562_LIVEINTERRUPTREG1_OTPCRC_MASK  (0x1 << 6)
#define TAS2562_LIVEINTERRUPTREG1_OTPCRC_NOINTERRUPT  (0x0 << 6)
#define TAS2562_LIVEINTERRUPTREG1_OTPCRC_INTERRUPT  (0x1 << 6)
#define TAS2562_LIVEINTERRUPTREG1_BROWNOUTFLAG_MASK  (0x1 << 1)
#define TAS2562_LIVEINTERRUPTREG1_BROWNOUTFLAG_NOINTERRUPT  (0x0 << 1)
#define TAS2562_LIVEINTERRUPTREG1_BROWNOUTFLAG_INTERRUPT  (0x1 << 1)
#define TAS2562_LIVEINTERRUPTREG1_BROWNOUTDETECTED_MASK  (0x1 << 1)
#define TAS2562_LIVEINTERRUPTREG1_BROWNOUTDETECTED_NOINTERRUPT  (0x0 << 1)
#define TAS2562_LIVEINTERRUPTREG1_BROWNOUTDETECTED_INTERRUPT  (0x1 << 1)

    /* Latched-Interrupt Reg0 */
#define TAS2562_LATCHEDINTERRUPTREG0  TAS2562_REG(0x0, 0x0, 0x24)
#define TAS2562_LATCHEDINTERRUPTREG0_LIMMUTESTICKY_MASK  (0x1 << 7)
#define TAS2562_LATCHEDINTERRUPTREG0_LIMMUTESTICKY_NOINTERRUPT  (0x0 << 7)
#define TAS2562_LATCHEDINTERRUPTREG0_LIMMUTESTICKY_INTERRUPT  (0x1 << 7)
#define TAS2562_LATCHEDINTERRUPTREG0_LIMINFHLDSTICKY_MASK  (0x1 << 6)
#define TAS2562_LATCHEDINTERRUPTREG0_LIMINFHLDSTICKY_NOINTERRUPT  (0x0 << 6)
#define TAS2562_LATCHEDINTERRUPTREG0_LIMINFHLDSTICKY_INTERRUPT  (0x1 << 6)
#define TAS2562_LATCHEDINTERRUPTREG0_LIMMAXATNSTICKY_MASK  (0x1 << 5)
#define TAS2562_LATCHEDINTERRUPTREG0_LIMMAXATNSTICKY_NOINTERRUPT  (0x0 << 5)
#define TAS2562_LATCHEDINTERRUPTREG0_LIMMAXATNSTICKY_INTERRUPT  (0x1 << 5)
#define TAS2562_LATCHEDINTERRUPTREG0_VBATLESSTHANINFSTICKY_MASK  (0x1 << 4)
#define TAS2562_LATCHEDINTERRUPTREG0_VBATLESSTHANINFSTICKY_NOINTERRUPT \
	(0x0 << 4)
#define TAS2562_LATCHEDINTERRUPTREG0_VBATLESSTHANINFSTICKY_INTERRUPT  (0x1 << 4)
#define TAS2562_LATCHEDINTERRUPTREG0_LIMACTIVEFLAGSTICKY_MASK  (0x1 << 3)
#define TAS2562_LATCHEDINTERRUPTREG0_LIMACTIVEFLAGSTICKY_NOINTERRUPT  (0x0 << 3)
#define TAS2562_LATCHEDINTERRUPTREG0_LIMACTIVEFLAGSTICKY_INTERRUPT  (0x1 << 3)
#define TAS2562_LATCHEDINTERRUPTREG0_TDMCLOCKERRORSTICKY_MASK  (0x1 << 2)
#define TAS2562_LATCHEDINTERRUPTREG0_TDMCLOCKERRORSTICKY_NOINTERRUPT  (0x0 << 2)
#define TAS2562_LATCHEDINTERRUPTREG0_TDMCLOCKERRORSTICKY_INTERRUPT  (0x1 << 2)
#define TAS2562_LATCHEDINTERRUPTREG0_OCEFLAGSTICKY_MASK  (0x1 << 1)
#define TAS2562_LATCHEDINTERRUPTREG0_OCEFLAGSTICKY_NOINTERRUPT  (0x0 << 1)
#define TAS2562_LATCHEDINTERRUPTREG0_OCEFLAGSTICKY_INTERRUPT  (0x1 << 1)
#define TAS2562_LATCHEDINTERRUPTREG0_OTEFLAGSTICKY_MASK  (0x1 << 0)
#define TAS2562_LATCHEDINTERRUPTREG0_OTEFLAGSTICKY_NOINTERRUPT  (0x0 << 0)
#define TAS2562_LATCHEDINTERRUPTREG0_OTEFLAGSTICKY_INTERRUPT  (0x1 << 0)

    /* Latched-Interrupt Reg1 */
#define TAS2562_LATCHEDINTERRUPTREG1  TAS2562_REG(0x0, 0x0, 0x25)
#define TAS2562_LATCHEDINTERRUPTREG1_PDMAUDDATAINVALIDSTICKY_MASK  (0x1 << 7)
#define TAS2562_LATCHEDINTERRUPTREG1_PDMAUDDATAINVALIDSTICKY_NOINTERRUPT \
	(0x0 << 7)
#define TAS2562_LATCHEDINTERRUPTREG1_PDMAUDDATAINVALIDSTICKY_INTERRUPT \
	(0x1 << 7)
#define TAS2562_LATCHEDINTERRUPTREG1_VBATOVLOSTICKY_MASK  (0x1 << 3)
#define TAS2562_LATCHEDINTERRUPTREG1_VBATOVLOSTICKY_NOINTERRUPT  (0x0 << 3)
#define TAS2562_LATCHEDINTERRUPTREG1_VBATOVLOSTICKY_INTERRUPT  (0x1 << 3)
#define TAS2562_LATCHEDINTERRUPTREG1_VBATUVLOSTICKY_MASK  (0x1 << 2)
#define TAS2562_LATCHEDINTERRUPTREG1_VBATUVLOSTICKY_NOINTERRUPT  (0x0 << 2)
#define TAS2562_LATCHEDINTERRUPTREG1_VBATUVLOSTICKY_INTERRUPT  (0x1 << 2)
#define TAS2562_LATCHEDINTERRUPTREG1_BROWNOUTFLAGSTICKY_MASK  (0x1 << 1)
#define TAS2562_LATCHEDINTERRUPTREG1_BROWNOUTFLAGSTICKY_NOINTERRUPT  (0x0 << 1)
#define TAS2562_LATCHEDINTERRUPTREG1_BROWNOUTFLAGSTICKY_INTERRUPT  (0x1 << 1)
#define TAS2562_LATCHEDINTERRUPTREG1_PDMCLOCKERRORSTICKY_MASK  (0x1 << 0)
#define TAS2562_LATCHEDINTERRUPTREG1_PDMCLOCKERRORSTICKY_NOINTERRUPT  (0x0 << 0)
#define TAS2562_LATCHEDINTERRUPTREG1_PDMCLOCKERRORSTICKY_INTERRUPT  (0x1 << 0)

    /* Latched-Interrupt Reg2 */
#define TAS2562_LATCHEDINTERRUPTREG2  TAS2562_REG(0x0, 0x0, 0x26)

    /* Latched-Interrupt Reg3 */
#define TAS2562_LATCHEDINTERRUPTREG3  TAS2562_REG(0x0, 0x0, 0x27)

    /* Latched-Interrupt Reg4 */
#define TAS2562_LATCHEDINTERRUPTREG4  TAS2562_REG(0x0, 0x0, 0x28)

    /* Latched-Interrupt Reg5 */
#define TAS2562_LATCHEDINTERRUPTREG5  TAS2562_REG(0x0, 0x0, 0x29)

    /* INT STATUS */
#define TAS2562_INTSTATUS  TAS2562_REG(0x0, 0x0, 0x78)
#define TAS2562_INTSTATUS_CLASSD  (0x1 << 2)
#define TAS2562_INTSTATUS_DAC  (0x1 << 3)

    /* VBAT MSB */
#define TAS2562_VBATMSB  TAS2562_REG(0x0, 0x0, 0x2A)
#define TAS2562_VBATMSB_VBATMSB70_MASK  (0xff << 0)

    /* VBAT LSB */
#define TAS2562_VBATLSB  TAS2562_REG(0x0, 0x0, 0x2B)
#define TAS2562_VBATLSB_VBATLSB74_MASK  (0xf << 4)

    /* TEMP */
#define TAS2562_TEMP  TAS2562_REG(0x0, 0x0, 0x2C)
#define TAS2562_TEMP_TEMPMSB70_MASK  (0xff << 0)


    /* Interrupt Configuration */
#define TAS2562_INTERRUPTCONFIGURATION  TAS2562_REG(0x0, 0x0, 0x30)
#define TAS2562_INTERRUPTCONFIGURATION_LTCHINTCLEAR_MASK (0x1 << 2)
#define TAS2562_INTERRUPTCONFIGURATION_LTCHINTCLEAR (0x1 << 2)
#define TAS2562_INTERRUPTCONFIGURATION_PININTCONFIG10_MASK  (0x3 << 0)
#define TAS2562_INTERRUPTCONFIGURATION_PININTCONFIG10_ASSERTONLIVEINTERRUPTS \
	(0x0 << 0)
#define \
TAS2562_INTERRUPTCONFIGURATION_PININTCONFIG10_ASSERTONLATCHEDINTERRUPTS \
	(0x1 << 0)
#define \
TAS2562_INTERRUPTCONFIGURATION_PININTCONFIG10_ASSERT2MSONLIVEINTERRUPTS \
	(0x2 << 0)
#define \
TAS2562_INTERRUPTCONFIGURATION_PININTCONFIG10_ASSERT2MSONLATCHEDINTERRUPTS \
	(0x3 << 0)

    /* Digital Input Pin Pull Down */
#define TAS2562_DIGITALINPUTPINPULLDOWN  TAS2562_REG(0x0, 0x0, 0x31)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNSDOUT_MASK  (0x1 << 7)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNSDOUT_DISABLED  (0x0 << 7)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNSDOUT_ENABLED  (0x1 << 7)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNSDIN_MASK  (0x1 << 6)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNSDIN_DISABLED  (0x0 << 6)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNSDIN_ENABLED  (0x1 << 6)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNFSYNC_MASK  (0x1 << 5)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNFSYNC_DISABLED  (0x0 << 5)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNFSYNC_ENABLED  (0x1 << 5)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNSBCLK_MASK  (0x1 << 4)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNSBCLK_DISABLED  (0x0 << 4)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNSBCLK_ENABLED  (0x1 << 4)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNPDMD0_MASK  (0x1 << 3)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNPDMD0_DISABLED  (0x0 << 3)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNPDMD0_ENABLED  (0x1 << 3)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNPDMD1_MASK  (0x1 << 2)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNPDMD1_DISABLED  (0x0 << 2)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNPDMD1_ENABLED  (0x1 << 2)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNPDMCK0_MASK  (0x1 << 1)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNPDMCK0_DISABLED  (0x0 << 1)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNPDMCK0_ENABLED  (0x1 << 1)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNPDMCK1_MASK  (0x1 << 0)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNPDMCK1_DISABLED  (0x0 << 0)
#define TAS2562_DIGITALINPUTPINPULLDOWN_WKPULLDOWNPDMCK1_ENABLED  (0x1 << 0)

    /* Misc IRQ */
#define TAS2562_MISCIRQ  TAS2562_REG(0x0, 0x0, 0x32)
#define TAS2562_MISCIRQ_IRQZREQD_MASK  (0x1 << 7)
#define TAS2562_MISCIRQ_IRQZREQD_ACTIVEHIGH  (0x0 << 7)
#define TAS2562_MISCIRQ_IRQZREQD_ACTIVELOW  (0x1 << 7)
#define TAS2562_MISCIRQ_IRQZBITBANG_MASK  (0x1 << 0)
#define TAS2562_MISCIRQ_IRQZBITBANG_IRQZINPUTBUF0  (0x0 << 0)
#define TAS2562_MISCIRQ_IRQZBITBANG_IRQZINPUTBUF1  (0x1 << 0)

#define TAS2562_BOOSTCONFIGURATION2 TAS2562_REG(0x0, 0x0, 0x34)
#define TAS2562_BOOSTCONFIGURATION2_BOOSTMAXVOLTAGE_MASK  (0x0f << 0)

#define TAS2562_BOOSTSLOPE TAS2562_REG(0x0, 0x0, 0x35)
#define TAS2562_BOOSTSLOPE_MASK		(0x3 << 2)
#define TAS2562_BOOSTSLOPE_3AV		(0x1 << 2)
#define TAS2562_BOOSTSLOPE_2AV		(0x2 << 2)

    /* Clock Configuration */
#define TAS2562_CLOCKCONFIGURATION  TAS2562_REG(0x0, 0x0, 0x38)
#define TAS2562_CLOCKCONFIGURATION_SBCLKTOFS52_MASK  (0xf << 2)
#define TAS2562_CLOCKCONFIGURATION_SBCLKtoFS52_16  (0x0 << 2)
#define TAS2562_CLOCKCONFIGURATION_SBCLKtoFS52_24  (0x1 << 2)
#define TAS2562_CLOCKCONFIGURATION_SBCLKtoFS52_32  (0x2 << 2)
#define TAS2562_CLOCKCONFIGURATION_SBCLKtoFS52_48  (0x3 << 2)
#define TAS2562_CLOCKCONFIGURATION_SBCLKtoFS52_64  (0x4 << 2)
#define TAS2562_CLOCKCONFIGURATION_SBCLKtoFS52_96  (0x5 << 2)
#define TAS2562_CLOCKCONFIGURATION_SBCLKtoFS52_128  (0x6 << 2)
#define TAS2562_CLOCKCONFIGURATION_SBCLKtoFS52_192  (0x7 << 2)
#define TAS2562_CLOCKCONFIGURATION_SBCLKtoFS52_256  (0x8 << 2)
#define TAS2562_CLOCKCONFIGURATION_SBCLKtoFS52_384  (0x9 << 2)
#define TAS2562_CLOCKCONFIGURATION_SBCLKtoFS52_512  (0xa << 2)
#define TAS2562_CLOCKCONFIGURATION_DISCLKRATEDETECT10_MASK  (0x3 << 0)
#define TAS2562_CLOCKCONFIGURATION_DISCLKRATEDETECT10_DISABLED  (0x1 << 0)
#define TAS2562_CLOCKCONFIGURATION_DISCLKRATEDETECT10_ENABLED  (0x0 << 0)

#define TAS2562_VBATFILTER TAS2562_REG(0x0, 0x0, 0x3b)
#define TAS2562_CLASSHRELEASETIMER TAS2562_REG(0x0, 0x0, 0x3c)

#define TAS2562_BOOST_CFG4 TAS2562_REG(0x0, 0x0, 0x40)
#define TAS2562_BOOST_ILIM_MASK (0x3f << 0)
#define TAS2562_BOOST_ILIM_DEFAULT (0x36)

#define TAS2562_ICN_THRESHOLD_REG TAS2562_REG(0x0, 0x2, 0x64)
#define TAS2562_ICN_HYSTERESIS_REG TAS2562_REG(0x0, 0x2, 0x6c)

#define TAS2562_ICN_SW_REG TAS2562_REG(0x0, 0x0, 0x3e)
#define TAS2562_ICN_SW_MASK (0x01 << 4)
#define TAS2562_ICN_SW_ENABLE  (0x10)
#define TAS2562_ICN_SW_DISABLE  (0x00)
#define TAS2562_TESTPAGECONFIGURATION TAS2562_REG(0x0, 0xfd, 0xd)
#define TAS2562_CLASSDCONFIGURATION1	TAS2562_REG(0x0, 0xfd, 0x19)
#define TAS2562_CLASSDCONFIGURATION2	TAS2562_REG(0x0, 0xfd, 0x32)
#define TAS2562_CLASSDCONFIGURATION3	TAS2562_REG(0x0, 0xfd, 0x33)
#define TAS2562_CLASSDCONFIGURATION4	TAS2562_REG(0x0, 0xfd, 0x3f)
#define TAS2562_EFFICIENCYCONFIGURATION	TAS2562_REG(0x0, 0xfd, 0x5f)
#define TAS2562_OSC_BOOST_CLK_MASK	(0x01 << 0x2)
#define TAS2562_OSC_BOOST_CLK		(0x01 << 0x2)

#define TAS2562_CLASSHHEADROOM TAS2562_REG(0x64, 0x7, 0x48)
#define TAS2562_CLASSHHYSTERESIS TAS2562_REG(0x64, 0x7, 0x4c)
#define TAS2562_CLASSHMTCT TAS2562_REG(0x64, 0x5, 0x4c)

    /* Revision and PG ID */
#define TAS2562_REVISIONANDPGID  TAS2562_REG(0x0, 0x0, 0x7D)
#define TAS2562_REVISIONANDPGID_REVISIONID74_MASK  (0xf << 4)
#define TAS2562_REVISIONANDPGID_PGID30_MASK  (0xf << 0)

    /* I2C Checksum */
#define TAS2562_I2CCHECKSUM  TAS2562_REG(0x0, 0x0, 0x7E)
#define TAS2562_I2CCHECKSUM_I2CCHECKSUM70_MASK  (0xff << 0)

    /* Book */
#define TAS2562_BOOK  TAS2562_REG(0x0, 0x0, 0x7F)
#define TAS2562_BOOK_BOOK70_MASK  (0xff << 0)

#define TAS2562_POWER_ACTIVE 0
#define TAS2562_POWER_MUTE 1
#define TAS2562_POWER_SHUTDOWN 2

#define ERROR_NONE		0x0000000
#define ERROR_PLL_ABSENT	0x0000000
#define ERROR_DEVA_I2C_COMM	0x0000000
#define ERROR_DEVB_I2C_COMM	0x0000000
#define ERROR_CLOCK			0x0000000
#define ERROR_YRAM_CRCCHK	0x0000001
#define ERROR_OVER_CURRENT	0x0000002
#define ERROR_DIE_OVERTEMP	0x0000004
#define ERROR_OVER_VOLTAGE	0x0000008
#define ERROR_UNDER_VOLTAGE	0x0000010
#define ERROR_BROWNOUT		0x0000020
#define ERROR_CLASSD_PWR	0x0000040
#define ERROR_FAILSAFE      0x4000000

#define CHECK_PERIOD	5000	/* 5 second */

#define TAS2562_I2C_RETRY_COUNT      3
#define ERROR_I2C_SUSPEND           -1
#define ERROR_I2C_FAILED            -2

struct tas2562_register {
int book;
int page;
int reg;
};

struct tas2562_dai_cfg {
unsigned int dai_fmt;
unsigned int tdm_delay;
};

enum channel {
	channel_left = 0x01,
	channel_right = 0x02,
	channel_both = channel_left|channel_right
};

struct tas2562_priv {
struct device *dev;
struct i2c_client *client;
struct regmap *regmap;
struct mutex dev_lock;
struct delayed_work irq_work;
struct delayed_work init_work;
struct hrtimer mtimer;
bool mb_power_up;
int mn_power_state;
int mn_l_current_book;
int mn_l_current_page;
int mn_r_current_book;
int mn_r_current_page;
int mn_l_addr;
int mn_r_addr;
int mn_asi_format;
int mn_reset_gpio;
int mn_irq_gpio;
int mn_irq;
int mn_reset_gpio2;
int mn_irq_gpio2;
int mn_irq2;
bool mb_irq_eable;
int mn_sampling_rate;
int mn_frame_size;
int mn_ppg;
int mn_ch_size;
int mn_slot_width;
int mn_pcm_format;
bool mb_mute;
bool dac_mute;
bool i2c_suspend;
int mn_channels;
int spk_l_control;
int spk_r_control;
int icn_sw;
/* Added for Boost Clock Source Change - Mute Issue */
int mn_bst_clk_src;
int (*read)(struct tas2562_priv *p_tas2562, enum channel chn,
	unsigned int reg, unsigned int *pValue);
int (*write)(struct tas2562_priv *p_tas2562, enum channel chn,
	unsigned int reg, unsigned int Value);
int (*bulk_read)(struct tas2562_priv *p_tas2562, enum channel chn,
	unsigned int reg, unsigned char *p_data, unsigned int len);
int (*bulk_write)(struct tas2562_priv *p_tas2562, enum channel chn,
	unsigned int reg, unsigned char *p_data, unsigned int len);
int (*update_bits)(struct tas2562_priv *p_tas2562, enum channel chn,
	unsigned int reg, unsigned int mask, unsigned int value);
void (*hw_reset)(struct tas2562_priv *p_tas2562);
void (*clear_irq)(struct tas2562_priv *p_tas2562);
void (*enable_irq)(struct tas2562_priv *p_tas2562, bool enable);
    /* device is working, but system is suspended */
int (*runtime_suspend)(struct tas2562_priv *p_tas2562);
int (*runtime_resume)(struct tas2562_priv *p_tas2562);
bool mb_runtime_suspend;

unsigned int mn_err_code;
#ifdef CONFIG_TAS2562_CODEC
struct mutex codec_lock;
#endif

#ifdef CONFIG_TAS2562_MISC
int mn_dbg_cmd;
int mn_current_reg;
struct mutex file_lock;
#endif

/* Added for Mute Issue */
struct delayed_work status_work;
int mn_status_check;
int mn_status_period;

/* Added for direct power mode support */
int pwr_mode;
int ilimit;
};

#endif /* __TAS2562_ */
