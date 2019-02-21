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

#include "sam.h"
#include "app_veneer.h"
#include "main.h"

volatile uint8_t rtc_alarm_flag = 1;

void rtc_alarm_callback(void)
{
	rtc_alarm_flag = 1;
}

void print_title(void)
{
	nsc_puts((uint8_t *)"\n\r----------------------------------------------------------------------------------");
	nsc_puts((uint8_t *)"\n\r|              Customer B - Non-Trusted application - Standard                   |");
	nsc_puts((uint8_t *)"\n\r----------------------------------------------------------------------------------");
	nsc_puts((uint8_t *)"\n\n\r  &&   &   &&&   &&   &      &&&&& &&&&&   &   &  &&&&& &&&&& &&&&&  &&&&");
	nsc_puts((uint8_t *)"\n\r  & &  &  &   &  & &  &        &   &    &  &   &  &       &   &      &   &");
	nsc_puts((uint8_t *)"\n\r  &  & &  &   &  &  & &  &&&   &   &&&&&   &   &   &&&&   &   &&&&&  &    &");
	nsc_puts((uint8_t *)"\n\r  &  & &  &   &  &  & &        &   &   &   &   &      &   &   &      &   &");
	nsc_puts((uint8_t *)"\n\r  &   &&   &&&   &   &&        &   &    &  &&&&&  &&&&    &   &&&&&  &&&&");
	nsc_puts((uint8_t *)"\n\n\r                                    &&&&");
	nsc_puts((uint8_t *)"\n\r                                 &&&    &&&");
	nsc_puts((uint8_t *)"\n\r                                &&        &&");
	nsc_puts((uint8_t *)"\n\r                                &&        &&");
	nsc_puts((uint8_t *)"\n\r                                &&        &&   &&&&&");
	nsc_puts((uint8_t *)"\n\r                                &&        &&");
	nsc_puts((uint8_t *)"\n\r                                &&        &&   &&&&&");
	nsc_puts((uint8_t *)"\n\r                                &&        &&");
	nsc_puts((uint8_t *)"\n\r                                &&        &&   &&&&&");
	nsc_puts((uint8_t *)"\n\r                                &&        &&");
	nsc_puts((uint8_t *)"\n\r                                &&  &&&&  &&   &&&&&");
	nsc_puts((uint8_t *)"\n\r                                &&  &&&&  &&");
	nsc_puts((uint8_t *)"\n\r                                &&  &&&&  &&   &&&&&");
	nsc_puts((uint8_t *)"\n\r                                &&  &&&&  &&");
	nsc_puts((uint8_t *)"\n\r                                &&  &&&&  &&");
	nsc_puts((uint8_t *)"\n\r                              &&&&  &&&&  &&&&");
	nsc_puts((uint8_t *)"\n\r                             &&&    &&&&     &&&");
	nsc_puts((uint8_t *)"\n\r                            &&   &&    &&&&&   &&");
	nsc_puts((uint8_t *)"\n\r                           &&  &&      &&&&&&   &&");
	nsc_puts((uint8_t *)"\n\r                          &&  &&   &&&&&&&&&&&   &&");
	nsc_puts((uint8_t *)"\n\r                          &&  &    &&&&&&&&&&&   &&");
	nsc_puts((uint8_t *)"\n\r                          &&  &&&&&&&&&&&&&&&&   &&");
	nsc_puts((uint8_t *)"\n\r                           &&  &&&&&&&&&&&&&&   &&");
	nsc_puts((uint8_t *)"\n\r                            &&   &&&&&&&&&&&   &&");
	nsc_puts((uint8_t *)"\n\r                             &&      &&&     &&");
	nsc_puts((uint8_t *)"\n\r                               &&&&&&&&&&&&&&");
	nsc_puts((uint8_t *)"\n\n\r------------------------------ Color Caption  ----------------------------------");
	nsc_puts((uint8_t *)SET_FONT_COLOUR_GREEN);
	nsc_puts((uint8_t *)"\n\n\r # : Secure code execution (Trusted) ");
	nsc_puts((uint8_t *)SET_FONT_COLOUR_YELLOW);
	nsc_puts((uint8_t *)"\n\r # : Non-Secure-Callable code execution");
	nsc_puts((uint8_t *)SET_FONT_COLOUR_RED);
	nsc_puts((uint8_t *)"\n\r # : Non-Secure code execution (Non-Trusted)");
	nsc_puts((uint8_t *)"\n\n\r--------------------------------------------------------------------------------");
}

/* Non-secure main() */
int main(void)
{
	uint32_t temperature;

	/* Clear Terminal Window */
	nsc_puts((uint8_t *)CLEAR_TERMINAL_WINDOW);

	/* Print application Title*/
	print_title();

	nsc_puts((uint8_t *)SET_FONT_COLOUR_RED);
	nsc_puts((uint8_t *)"\n\n\r- Configure RTC to generate 5 second alarm\n\r  ->");
	nsc_rtc_CMP0_callback_register(rtc_alarm_callback);

	/* Configure RTC to generate 5 second alarm */
	nsc_puts((uint8_t *)SET_FONT_COLOUR_RED);
	nsc_puts((uint8_t *)"\n\r  ->");
	nsc_rtc_CMP0_val_set(RTC_CMP_VALUE);

	nsc_puts((uint8_t *)SET_FONT_COLOUR_RED);
	nsc_puts((uint8_t *)"\n\r  ->");
	nsc_rtc_enable_CMP0_interrupt();

	while (1) {
		if (rtc_alarm_flag) {
			nsc_puts((uint8_t *)SET_FONT_COLOUR_RED);
			nsc_puts((uint8_t *)"\n\n\n\r- RTC Wake-up");
			rtc_alarm_flag = 0;

			/* LED ON */
			nsc_puts((uint8_t *)"\n\r- Switch-on secure LED\n\r  ->");
			nsc_led_on();



			/* LED OFF */
			nsc_puts((uint8_t *)SET_FONT_COLOUR_RED);
			nsc_puts((uint8_t *)"\n\r- Switch-off secure LED\n\r  ->");
			nsc_led_off();

			/*Enter low power mode */
			nsc_puts((uint8_t *)SET_FONT_COLOUR_RED);
			nsc_puts((uint8_t *)"\n\r- Enter Standby mode\n\r  ->");
			nsc_enter_standby_mode();
		}
	}
}
