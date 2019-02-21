/**
 * \file
 *
 * \brief TrustZone secure gateway veneer implementation.
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
#include "app_veneer.h"
#include "arm_cmse.h"
#include <atmel_start.h>
#include "Secure_Functions/secure_led.h"
#include "Secure_Functions/secure_rtc.h"
#include "Secure_Functions/secure_lowpower.h"
#include "main.h"

/* ======== Non-secure callable functions defined by customer ======== */
/*
 * You may add your secure gateway veneer functions in this file
 * and the function declaration into trustzone_veneer.h.
 */

typedef void (*funcptr_void)(void);

void __attribute__((cmse_nonsecure_entry)) nsc_puts(uint8_t *string)
{
	printf("%s", string);
}

void __attribute__((cmse_nonsecure_entry)) nsc_putc(uint8_t c)
{
	putchar(c);
}

uint8_t __attribute__((cmse_nonsecure_entry)) nsc_getc(void)
{
	return getchar();
}

void __attribute__((cmse_nonsecure_entry)) nsc_led_on(void)
{
	printf(SET_FONT_COLOUR_YELLOW);
	printf("nsc_set_secure_led_on(); ->");
	secure_led_on();
	printf(RESET_FONT_COLOUR_DEFAULT);
}

void __attribute__((cmse_nonsecure_entry)) nsc_led_off(void)
{
	printf(SET_FONT_COLOUR_YELLOW);
	printf("nsc_set_secure_led_off(); ->");
	secure_led_off();
	printf(RESET_FONT_COLOUR_DEFAULT);
}

void __attribute__((cmse_nonsecure_entry)) nsc_led_toggle(void)
{
	printf(SET_FONT_COLOUR_YELLOW);
	printf("nsc_set_secure_led_toggle(); ->");
	secure_led_toggle();
	printf(RESET_FONT_COLOUR_DEFAULT);
}

void __attribute__((cmse_nonsecure_entry)) nsc_enter_standby_mode(void)
{
	printf(SET_FONT_COLOUR_YELLOW);
	printf("nsc_secure_enter_sleep_mode(); ->");
	secure_enter_sleep();
}

void __attribute__((cmse_nonsecure_entry)) nsc_rtc_enable_CMP0_interrupt(void)
{
	printf(SET_FONT_COLOUR_YELLOW);
	printf("secure_rtc_enable_CMP0_interrupt(); ->");
	secure_rtc_enable_CMP0_interrupt();
}

void __attribute__((cmse_nonsecure_entry)) nsc_rtc_CMP0_val_set(uint32_t cmp0_val)
{
	printf(SET_FONT_COLOUR_YELLOW);
	printf("secure_rtc_CMP0_val_set(%x); ->", (unsigned int)cmp0_val);
	secure_rtc_CMP0_val_set(cmp0_val);
}

void __attribute__((cmse_nonsecure_entry)) nsc_rtc_CMP0_callback_register(secure_void_cb_t pfunction)
{
	printf(SET_FONT_COLOUR_YELLOW);
	printf("secure_rtc_CMP0_register_callback(%x); ->", (unsigned int)pfunction);
	secure_rtc_CMP0_register_callback((funcptr_void)pfunction);
}

