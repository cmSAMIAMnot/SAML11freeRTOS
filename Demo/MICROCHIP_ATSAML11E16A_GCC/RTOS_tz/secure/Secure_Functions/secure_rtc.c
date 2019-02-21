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

#include "Secure_Functions/secure_rtc.h"
#include "main.h"

static volatile funcptr_void    secure_rtc_tamper_callback = 0;
static volatile funcptr_NS_void secure_rtc_CMP0_callback   = 0;

void RTC_Handler(void)
{
	uint32_t status;

	status = hri_rtcmode0_read_INTFLAG_reg(RTC);
	hri_rtcmode0_clear_INTFLAG_reg(RTC, RTC_MODE0_INTFLAG_Msk);

	if (status & RTC_MODE0_INTFLAG_TAMPER) {
		/* Tamper detected */
		secure_rtc_tamper_callback();
	}
	if (status & RTC_MODE0_INTFLAG_CMP0) {
		if (secure_rtc_CMP0_callback != 0)
			secure_rtc_CMP0_callback();
	}
}

void secure_rtc_tamper_callback_register(funcptr_void pfunction)
{
	secure_rtc_tamper_callback = pfunction;
	NVIC_EnableIRQ(RTC_IRQn);
	return;
}

void secure_rtc_CMP0_register_callback(funcptr_void pfunction)
{
	void *ptr;
	printf(SET_FONT_COLOUR_GREEN);

	ptr = cmse_check_pointed_object(pfunction, CMSE_NONSECURE);

	if (ptr != NULL) {
		/* Store callback address */
		printf("secure_rtc_CMP0_register_callback(%x);", (unsigned int)ptr);
		secure_rtc_CMP0_callback = cmse_nsfptr_create(ptr);
	} else {
		/* ERROR : Forbidden Callback Address Location - Application HALTED" */
		printf("ERROR : Forbidden Callback Address Location - Application HALTED");
		while (1)
			;
	}
	return;
}

void secure_rtc_enable_CMP0_interrupt(void)
{
	printf(SET_FONT_COLOUR_GREEN);
	printf("secure_rtc_enable_CMP0_interrupt();");

	hri_rtcmode0_clear_interrupt_CMP0_bit(RTC);
	hri_rtcmode0_set_INTEN_CMP0_bit(RTC);
}

void secure_rtc_CMP0_val_set(uint32_t cmp0_val)
{
	printf(SET_FONT_COLOUR_GREEN);
	printf("secure_rtc_enable_CMP0_interrupt(%x);", (unsigned int)cmp0_val);

	hri_rtcmode0_wait_for_sync(RTC, RTC_MODE0_SYNCBUSY_COMP0);
	hri_rtcmode0_write_COMP_reg(RTC, 0, cmp0_val);
}
