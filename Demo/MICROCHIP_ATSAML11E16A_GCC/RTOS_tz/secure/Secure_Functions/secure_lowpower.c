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

#include "Secure_Functions/secure_lowpower.h"
#include "main.h"

void secure_enter_sleep(void)
{

	printf(SET_FONT_COLOUR_GREEN);

	printf("secure_enter_sleep_mode()");

	/* Disable peripherals */
/*	secure_temp_sensor_disable(); */

	hri_sercomusart_clear_CTRLA_ENABLE_bit(SERCOM0);
	hri_sercomusart_wait_for_sync(SERCOM0, SERCOM_USART_SYNCBUSY_ENABLE);

	/* Set Low power Mode Efficiency for the Low Power Voltage Regulator (LPVREG)  */
	hri_supc_set_VREG_LPEFF_bit(SUPC);

	/* PDSW POwer Domain domain will be put in retention when entering STANDBY sleep mode */
	hri_pm_clear_STDBYCFG_PDCFG_bit(PM);

	/* 4kB SRAM out of 16kB will be retained in STANDBY */
	hri_pm_set_PWCFG_RAMPSWC_bf(PM, PM_PWCFG_RAMPSWC_12KB_Val);

	/* Configure PORTA for low power*/
	hri_port_write_WRCONFIG_reg(PORT_SEC,
	                            0,
	                            (uint32_t)(PORT_WRCONFIG_WRPINCFG | PORT_WRCONFIG_WRPMUX
	                                       | PORT_WRCONFIG_PINMASK(~(1 << 8)) | PORT_WRCONFIG_PMUX(0)));
	hri_port_write_WRCONFIG_reg(PORT_SEC,
	                            0,
	                            (uint32_t)(PORT_WRCONFIG_HWSEL | PORT_WRCONFIG_WRPINCFG | PORT_WRCONFIG_WRPMUX
	                                       | PORT_WRCONFIG_PINMASK(0xFFFF) | PORT_WRCONFIG_PMUX(0)));

	/* Enter STANDBY Sleep Mode */
	sleep(PM_SLEEPCFG_SLEEPMODE_STANDBY_Val);

	// WDT->CTRLA.bit.ENABLE = 1;
	hri_wdt_write_CLEAR_reg(WDT, WDT_CLEAR_CLEAR_KEY);

	/* - configure SERCOM1 I2C I/Os
	 PA16 : SDA			<-> SERCOM1 PAD[0]		<-> Peripheral MUX C
	 PA17 : SCL			<-> SERCOM1 PAD[1]		<-> Peripheral MUX C */
	gpio_set_pin_function(PIN_PA16, GPIO_PIN_FUNCTION_C);
	gpio_set_pin_function(PIN_PA17, GPIO_PIN_FUNCTION_C);

	/* - configure SERCOM0 USART I/Os (for console)
	 PA24 : UART_TX		<-> SERCOM0 PAD[2]		<-> Peripheral MUX C
	 PA25 : UART_RX		<-> SERCOM0 PAD[3]		<-> Peripheral MUX C */
	gpio_set_pin_function(PIN_PA24, GPIO_PIN_FUNCTION_C);
	gpio_set_pin_function(PIN_PA25, GPIO_PIN_FUNCTION_C);

	/* secure_temp_sensor_enable(); */

	hri_sercomusart_set_CTRLA_ENABLE_bit(SERCOM0);
	hri_sercomusart_wait_for_sync(SERCOM0, SERCOM_USART_SYNCBUSY_ENABLE);
}
