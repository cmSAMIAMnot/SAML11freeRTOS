/**
 * \file
 *
 * \brief Application implement
 *
 * Copyright (c) 2018 Microchip Technology Inc. and its subsidiaries.
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
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES,
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
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip
 * Support</a>
 */

#include "Secure_Functions/secure_pac.h"
#include "main.h"

void PAC_Handler(void)
{
	uint32_t status_INTFLAGAHB, status_INTFLAGA, status_INTFLAGB, status_INTFLAGC;

	status_INTFLAGAHB = hri_pac_read_INTFLAGAHB_reg(PAC_SEC);
	status_INTFLAGA   = hri_pac_read_INTFLAGA_reg(PAC_SEC);
	status_INTFLAGB   = hri_pac_read_INTFLAGB_reg(PAC_SEC);
	status_INTFLAGC   = hri_pac_read_INTFLAGC_reg(PAC_SEC);

	hri_pac_clear_INTFLAGAHB_reg(PAC_SEC, PAC_INTFLAGAHB_Msk);
	hri_pac_clear_INTFLAGA_reg(PAC_SEC, PAC_INTFLAGA_Msk);
	hri_pac_clear_INTFLAGB_reg(PAC_SEC, PAC_INTFLAGB_Msk);
	hri_pac_clear_INTFLAGC_reg(PAC_SEC, PAC_INTFLAGC_Msk);

	printf(SET_FONT_COLOUR_GREEN);

	printf("\n\r #### Malware detected : Forbidden peripheral access detected on ");

	if (status_INTFLAGAHB & PAC_INTFLAGAHB_FLASH) {
		printf("FLASH");
	}

	if (status_INTFLAGAHB & PAC_INTFLAGAHB_HPB0) {
		printf("HPB0");
	}

	if (status_INTFLAGAHB & PAC_INTFLAGAHB_HPB1) {
		printf("HPB1");
	}

	if (status_INTFLAGAHB & PAC_INTFLAGAHB_HPB2) {
		printf("HPB2");
	}

	if (status_INTFLAGAHB & PAC_INTFLAGAHB_HSRAMCPU) {
		printf("HSRAMCPU");
	}

	if (status_INTFLAGAHB & PAC_INTFLAGAHB_HSRAMDMAC) {
		printf("HSRAMDMAC");
	}

	if (status_INTFLAGAHB & PAC_INTFLAGAHB_HSRAMDSU) {
		printf("HSRAMDSU");
	}

	if (status_INTFLAGA & PAC_INTFLAGA_PAC) {
		printf("PAC");
	}

	if (status_INTFLAGA & PAC_INTFLAGA_PM) {
		printf("PM");
	}

	if (status_INTFLAGA & PAC_INTFLAGA_MCLK) {
		printf("MCLK");
	}

	if (status_INTFLAGA & PAC_INTFLAGA_RSTC) {
		printf("RSTC");
	}

	if (status_INTFLAGA & PAC_INTFLAGA_OSCCTRL) {
		printf("OSCCTRL");
	}

	if (status_INTFLAGA & PAC_INTFLAGA_SUPC) {
		printf("SUPC");
	}

	if (status_INTFLAGA & PAC_INTFLAGA_GCLK) {
		printf("GCLK");
	}

	if (status_INTFLAGA & PAC_INTFLAGA_WDT) {
		printf("WDT");
	}

	if (status_INTFLAGA & PAC_INTFLAGA_RTC) {
		printf("RTC");
	}

	if (status_INTFLAGA & PAC_INTFLAGA_EIC) {
		printf("EIC");
	}

	if (status_INTFLAGA & PAC_INTFLAGA_FREQM) {
		printf("FREQM");
	}

	if (status_INTFLAGA & PAC_INTFLAGA_PORT) {
		printf("PORT");
	}

	if (status_INTFLAGA & PAC_INTFLAGA_AC) {
		printf("AC");
	}

	if (status_INTFLAGB & PAC_INTFLAGB_IDAU) {
		printf("IDAU");
	}

	if (status_INTFLAGB & PAC_INTFLAGB_DSU) {
		printf("DSU");
	}

	if (status_INTFLAGB & PAC_INTFLAGB_NVMCTRL) {
		printf("NVMCTRL");
	}

	if (status_INTFLAGB & PAC_INTFLAGB_DMAC) {
		printf("DMAC");
	}

	if (status_INTFLAGC & PAC_INTFLAGC_EVSYS) {
		printf("EVSYS");
	}

	if (status_INTFLAGC & PAC_INTFLAGC_SERCOM0) {
		printf("SERCOM0");
	}

	if (status_INTFLAGC & PAC_INTFLAGC_SERCOM1) {
		printf("SERCOM1");
	}

	if (status_INTFLAGC & PAC_INTFLAGC_SERCOM2) {
		printf("SERCOM2");
	}

	if (status_INTFLAGC & PAC_INTFLAGC_TC0) {
		printf("TC0");
	}

	if (status_INTFLAGC & PAC_INTFLAGC_TC1) {
		printf("TC1");
	}

	if (status_INTFLAGC & PAC_INTFLAGC_TC2) {
		printf("TC2");
	}

	if (status_INTFLAGC & PAC_INTFLAGC_ADC) {
		printf("ADC");
	}

	if (status_INTFLAGC & PAC_INTFLAGC_DAC) {
		printf("DAC");
	}

	if (status_INTFLAGC & PAC_INTFLAGC_PTC) {
		printf("PTC");
	}

	if (status_INTFLAGC & PAC_INTFLAGC_TRNG) {
		printf("TRNG");
	}

	if (status_INTFLAGC & PAC_INTFLAGC_CCL) {
		printf("CCL");
	}

	if (status_INTFLAGC & PAC_INTFLAGC_OPAMP) {
		printf("OPAMP");
	}

	if (status_INTFLAGC & PAC_INTFLAGC_TRAM) {
		printf("TRAM");
	}

	printf("\n\r - Non-Secure read/write accesses ignored");

	printf(SET_FONT_COLOUR_GREEN);
}

void secure_pac_init(void)
{
	/* - Initialize PAC security */
	hri_pac_set_INTEN_ERR_bit(PAC_SEC);

	/* - Enable PAC interrupt at core level */
	NVIC_EnableIRQ(PAC_IRQn);
}
