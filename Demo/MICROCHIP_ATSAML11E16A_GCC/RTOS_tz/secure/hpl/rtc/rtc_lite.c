
/**
 * \file
 *
 * \brief RTC related functionality implementation.
 *
 * Copyright (c) 2017 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#include "rtc_lite.h"

/**
 * \brief Initialize RTC interface
 */
int8_t REAL_TIMER_COUNTER_init()
{

	hri_rtcmode0_wait_for_sync(RTC, RTC_MODE0_SYNCBUSY_SWRST);
	if (hri_rtcmode0_get_CTRLA_ENABLE_bit(RTC)) {
		hri_rtcmode0_clear_CTRLA_ENABLE_bit(RTC);
		hri_rtcmode0_wait_for_sync(RTC, RTC_MODE0_SYNCBUSY_ENABLE);
	}
	hri_rtcmode0_set_CTRLA_SWRST_bit(RTC);
	hri_rtcmode0_wait_for_sync(RTC, RTC_MODE0_SYNCBUSY_SWRST);

	hri_rtcmode0_write_CTRLA_reg(
	    RTC,
	    1 << RTC_MODE0_CTRLA_COUNTSYNC_Pos       /* COUNT Read Synchronization Enable: enabled */
	        | 1 << RTC_MODE0_CTRLA_PRESCALER_Pos /* Setting: 1 */
	        | 1 << RTC_MODE0_CTRLA_MATCHCLR_Pos  /* Clear on Match: enabled */
	        | 0x0 << RTC_MODE0_CTRLA_MODE_Pos    /* Operating Mode: 0x0 */
	        | 0 << RTC_MODE0_CTRLA_GPTRST_Pos);  /* GP Registers Reset On Tamper Enable: disabled */

	// hri_rtcmode0_write_COUNT_reg(RTC,0x0); /* Counter Value: 0x0 */

	hri_rtcmode0_write_EVCTRL_reg(
	    RTC,
	    0 << RTC_MODE0_EVCTRL_OVFEO_Pos          /* Overflow Event Output Enable: disabled */
	        | 0 << RTC_MODE2_EVCTRL_PERDEO_Pos   /* Periodic Interval Daily Event Output Enable: disabled */
	        | 0 << RTC_MODE0_EVCTRL_TAMPEVEI_Pos /* Tamper Event Input Enable: disabled */
	        | 1 << RTC_MODE0_EVCTRL_TAMPEREO_Pos /* Tamper Event output Enable: enabled */
	        | 0 << RTC_MODE0_EVCTRL_CMPEO0_Pos   /* Compare 0 Event Output Enable: disabled */
	        | 0 << RTC_MODE0_EVCTRL_PEREO0_Pos   /* Periodic Interval 0 Event Output Enable: disabled */
	        | 0 << RTC_MODE0_EVCTRL_PEREO1_Pos   /* Periodic Interval 1 Event Output Enable: disabled */
	        | 0 << RTC_MODE0_EVCTRL_PEREO2_Pos   /* Periodic Interval 2 Event Output Enable: disabled */
	        | 0 << RTC_MODE0_EVCTRL_PEREO3_Pos   /* Periodic Interval 3 Event Output Enable: disabled */
	        | 0 << RTC_MODE0_EVCTRL_PEREO4_Pos   /* Periodic Interval 4 Event Output Enable: disabled */
	        | 0 << RTC_MODE0_EVCTRL_PEREO5_Pos   /* Periodic Interval 5 Event Output Enable: disabled */
	        | 0 << RTC_MODE0_EVCTRL_PEREO6_Pos   /* Periodic Interval 6 Event Output Enable: disabled */
	        | 0 << RTC_MODE0_EVCTRL_PEREO7_Pos); /* Periodic Interval 7 Event Output Enable: disabled */

	hri_rtcmode0_write_INTEN_reg(
	    RTC,
	    0 << RTC_MODE0_INTENSET_OVF_Pos          /* Overflow Interrupt enable: disabled */
	        | 0 << RTC_MODE0_INTENSET_TAMPER_Pos /* Tamper Interrupt Enable: disabled */
	        | 1 << RTC_MODE0_INTENSET_CMP0_Pos   /* Compare 0 Interrupt Enable: enabled */
	        | 0 << RTC_MODE0_INTENSET_PER0_Pos   /* Periodic Interval 0 Output Enable: disabled */
	        | 0 << RTC_MODE0_INTENSET_PER1_Pos   /* Periodic Interval 1 Output Enable: disabled */
	        | 0 << RTC_MODE0_INTENSET_PER2_Pos   /* Periodic Interval 2 Output Enable: disabled */
	        | 0 << RTC_MODE0_INTENSET_PER3_Pos   /* Periodic Interval 3 Output Enable: disabled */
	        | 0 << RTC_MODE0_INTENSET_PER4_Pos   /* Periodic Interval 4 Output Enable: disabled */
	        | 0 << RTC_MODE0_INTENSET_PER5_Pos   /* Periodic Interval 5 Output Enable: disabled */
	        | 0 << RTC_MODE0_INTENSET_PER6_Pos   /* Periodic Interval 6 Output Enable: disabled */
	        | 0 << RTC_MODE0_INTENSET_PER7_Pos); /* Periodic Interval 7 Output Enable: disabled */

	hri_rtcmode0_write_COMP_reg(RTC, 0, 0x400); /* Compare Value: 0x400 */

	// hri_rtc_write_DBGCTRL_reg(RTC,0); /* Run in debug: 0 */

	// hri_rtc_write_FREQCORR_reg(RTC,0 << RTC_FREQCORR_SIGN_Pos /* Correction Sign: disabled */
	//		 | 0x0); /* Correction Value: 0x0 */

	// hri_rtc_write_GP_reg(RTC, 0 ,0x0); /* General Purpose: 0x0 */

	// hri_rtc_write_GP_reg(RTC, 1 ,0x0); /* General Purpose: 0x0 */

	// hri_rtcmode0_write_CTRLB_reg(RTC,0 << RTC_MODE2_CTRLB_ACTF_Pos /* Setting: 0 */
	//		 | 0 << RTC_MODE2_CTRLB_DEBF_Pos /* Setting: 0 */
	//		 | 0 << RTC_MODE2_CTRLB_DMAEN_Pos /* DMA Enable: disabled */
	//		 | 0 << RTC_MODE2_CTRLB_RTCOUT_Pos /* RTC Output Enable: disabled */
	//		 | 0 << RTC_MODE2_CTRLB_DEBASYNC_Pos /* Debouncer Asynchronous Enable: disabled */
	//		 | 0 << RTC_MODE2_CTRLB_DEBMAJ_Pos /* Debouncer Majority Enable: disabled */
	//		 | 0 << RTC_MODE2_CTRLB_SEPTO_Pos /* Separate Tamper Outputs: disabled */
	//		 | 0 << RTC_MODE2_CTRLB_GP0EN_Pos); /* General Purpose 0 Enable: disabled */

	hri_rtc_write_TAMPCTRL_reg(RTC,
	                           1 << RTC_TAMPCTRL_DEBNC0_Pos         /* Debounce Enable 0: enabled */
	                               | 0 << RTC_TAMPCTRL_DEBNC1_Pos   /* Debounce Enable 1: disabled */
	                               | 0 << RTC_TAMPCTRL_DEBNC2_Pos   /* Debounce Enable 2: disabled */
	                               | 0 << RTC_TAMPCTRL_DEBNC3_Pos   /* Debounce Enable 3: disabled */
	                               | 0 << RTC_TAMPCTRL_TAMLVL0_Pos  /* Tamper Level Select 0: disabled */
	                               | 0 << RTC_TAMPCTRL_TAMLVL1_Pos  /* Tamper Level Select 1: disabled */
	                               | 0 << RTC_TAMPCTRL_TAMLVL2_Pos  /* Tamper Level Select 2: disabled */
	                               | 0 << RTC_TAMPCTRL_TAMLVL3_Pos  /* Tamper Level Select 3: disabled */
	                               | 1 << RTC_TAMPCTRL_IN0ACT_Pos   /* Tamper Input 0 Action: 1 */
	                               | 0 << RTC_TAMPCTRL_IN1ACT_Pos   /* Tamper Input 1 Action: 0 */
	                               | 0 << RTC_TAMPCTRL_IN2ACT_Pos   /* Tamper Input 2 Action: 0 */
	                               | 0 << RTC_TAMPCTRL_IN3ACT_Pos); /* Tamper Input 3 Action: 0 */

	// hri_rtc_write_TAMPID_reg(RTC,0 << RTC_TAMPID_TAMPEVT_Pos /* Tamper Event Detected: disabled */
	//		 | 0 << RTC_TAMPID_TAMPID0_Pos /* Tamper Input 0 Detected: disabled */
	//		 | 0 << RTC_TAMPID_TAMPID1_Pos /* Tamper Input 1 Detected: disabled */
	//		 | 0 << RTC_TAMPID_TAMPID2_Pos /* Tamper Input 2 Detected: disabled */
	//		 | 0 << RTC_TAMPID_TAMPID3_Pos); /* Tamper Input 3 Detected: disabled */

	// hri_rtc_write_TAMPCTRLB_reg(RTC,0 << RTC_TAMPID_TAMPID0_Pos /* Active Layer Internal Select n: disabled */
	//		 | 0 << RTC_TAMPID_TAMPID1_Pos /* Active Layer Internal Select n: disabled */
	//		 | 0 << RTC_TAMPID_TAMPID2_Pos /* Active Layer Internal Select n: disabled */
	//		 | 0 << RTC_TAMPID_TAMPID3_Pos); /* Active Layer Internal Select n: disabled */

	hri_rtcmode0_write_CTRLA_ENABLE_bit(RTC, 1 << RTC_MODE0_CTRLA_ENABLE_Pos); /* Enable: enabled */

	return 0;
}
