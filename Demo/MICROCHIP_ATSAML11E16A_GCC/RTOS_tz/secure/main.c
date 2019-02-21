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

#include <atmel_start.h>
#include "main.h"
#include "arm_cmse.h"
#include "Secure_Functions/secure_led.h"
#include "Secure_Functions/secure_pac.h"
#include "Secure_Functions/secure_rtc.h"
#include "Secure_Functions/secure_tram.h"
#include "Secure_Functions/secure_wdt.h"
#include "Secure_Functions/secure_dataflash.h"

/* typedef for non-secure callback functions */
typedef void (*ns_funcptr_void)(void) __attribute__((cmse_nonsecure_call));

/* ------- PORT_SECURE CONFIGURATIONS ----------- */
void port_sec_init(void)
{
	/* - configure SERCOM1 I2C I/Os
	 PA16 : SDA			<-> SERCOM1 PAD[0]		<-> Peripheral MUX C
	 PA17 : SCL			<-> SERCOM1 PAD[1]		<-> Peripheral MUX C */
	gpio_set_pin_function(I2C_SDA_PIN, GPIO_PIN_FUNCTION_C);
	gpio_set_pin_function(I2C_SCL_PIN, GPIO_PIN_FUNCTION_C);

	/* - configure SERCOM0 USART I/Os (for console)
	 PA24 : UART_TX		<-> SERCOM0 PAD[2]		<-> Peripheral MUX C
	 PA25 : UART_RX		<-> SERCOM0 PAD[3]		<-> Peripheral MUX C */
	gpio_set_pin_function(STDIO_TXD_PIN, GPIO_PIN_FUNCTION_C);
	gpio_set_pin_function(STDIO_RXD_PIN, GPIO_PIN_FUNCTION_C);

	/* Configure TAMPER pins
	PA08 as RTC IN0 (peripheral MUX I)
	PA09 as RTC OUT (GPIO output on level low)*/
	gpio_set_pin_function(TAMPER_IN_PIN, GPIO_PIN_FUNCTION_I);
	gpio_set_pin_pull_mode(TAMPER_IN_PIN, GPIO_PULL_UP);
	gpio_set_pin_level(TAMPER_IN_PIN, true);

	gpio_set_pin_direction(TAMPER_0V, GPIO_DIRECTION_OUT);
	gpio_set_pin_level(TAMPER_0V, false);
}

void Tamper_Message(void)
{
	wdt_enable(&WATCHDOG);

	hri_sercomusart_set_CTRLA_ENABLE_bit(SERCOM0);
	hri_sercomusart_wait_for_sync(SERCOM0, SERCOM_USART_SYNCBUSY_ENABLE);

	/* - configure SERCOM0 USART I/Os (for console)
	 PA24 : UART_TX		<-> SERCOM0 PAD[2]		<-> Peripheral MUX C
	 PA25 : UART_RX		<-> SERCOM0 PAD[3]		<-> Peripheral MUX C */
	gpio_set_pin_function(PIN_PA24, GPIO_PIN_FUNCTION_C);
	gpio_set_pin_function(PIN_PA25, GPIO_PIN_FUNCTION_C);

	printf(SET_FONT_COLOUR_GREEN);
	printf(NO_CR_LF);

	printf("\n\r --- WARNING --- TAMPER DETECTED ");
	printf("\n\r - TRAM and Dataflash content erased automatically");
	printf("\n\r - Stop WDT refresh to recover application ");

	NVIC_DisableIRQ(RTC_IRQn);
	while (1)
		;
}

void HardFault_Handler(void)
{
	wdt_enable(&WATCHDOG);

	printf(SET_FONT_COLOUR_GREEN);
	printf(NO_CR_LF);

	printf("\n\r #### Malware detected : Denies access to trusted memory region  ");
	printf("\n\r - Erase TRAM ");
	printf("\n\r - Stop WDT refresh to recover application");
	printf("\nHARDFAULT  Status sICSR: %08X\n", SCB->ICSR);
	/*printf("\nnsICSR: %08X\n", SCB_NS->SICSR );*/
	printf("SAU: %08X\n", SAU->CTRL);
	while (1)
		;
}

void secure_menu_print_fuses_settings(void)
{
	volatile uint32_t reg_val, IDAU_reg;
	uint8_t           bootprot, bs, bnsc, as, ansc, ds, rs;

	/* - Read BS and BNSC in IDAU_SCFGB register */
	IDAU_reg = IDAU->SCFGB.reg;
	bs       = (IDAU_reg & IDAU_SCFGB_BS_Msk);
	bnsc     = (IDAU_reg & IDAU_SCFGB_BNSC_Msk);
	bootprot = (IDAU_reg & IDAU_SCFGB_BOOTPROT_Msk);

	/* - Read AS , ANSC , DS in IDAU_SCFGA register */
	IDAU_reg = IDAU->SCFGA.reg;
	as       = (IDAU_reg & IDAU_SCFGA_AS_Msk);
	ansc     = (IDAU_reg & IDAU_SCFGA_ANSC_Msk);
	ds       = (IDAU_reg & IDAU_SCFGA_DS_Msk);

	/* - Read RS , ANSC , DS in IDAU_SCFGR register */
	IDAU_reg = IDAU->SCFGR.reg;
	rs       = (IDAU_reg & IDAU_SCFGR_RS_Msk);

	printf("\n\n\rBS: 0x%02x", bs);
	printf("\t\tBNSC: 0x%02x", bnsc);
	printf("\n\rBOOTPROT: 0x%02x", bootprot);
	printf("\t\tAS: 0x%02x", as);
	printf("\n\rANSC: 0x%02x", ansc);
	printf("\t\tDS: 0x%02x", ds);
	printf("\n\rRS: 0x%02x", rs);

	reg_val = hri_pac_read_NONSECA_reg(PAC_SEC);

	printf("\n\n\rPAC: %s", (reg_val & PAC_NONSECA_PAC) ? "Non-Secure" : "Secure");
	printf("\t\tPM: %s", (reg_val & PAC_NONSECA_PM) ? "Non-Secure" : "Secure");
	printf("\n\rMCLK: %s", (reg_val & PAC_NONSECA_MCLK) ? "Non-Secure" : "Secure");
	printf("\t\tRSTC: %s", (reg_val & PAC_NONSECA_RSTC) ? "Non-Secure" : "Secure");
	printf("\n\rOSCCTRL: %s", (reg_val & PAC_NONSECA_OSCCTRL) ? "Non-Secure" : "Secure");
	printf("\t\tOSC32KCTRL: %s", (reg_val & PAC_NONSECA_OSC32KCTRL) ? "Non-Secure" : "Secure");
	printf("\n\rSUPC: %s", (reg_val & PAC_NONSECA_SUPC) ? "Non-Secure" : "Secure");
	printf("\t\tGCLK: %s", (reg_val & PAC_NONSECA_GCLK) ? "Non-Secure" : "Secure");
	printf("\n\rWDT: %s", (reg_val & PAC_NONSECA_WDT) ? "Non-Secure" : "Secure");
	printf("\t\tRTC: %s", (reg_val & PAC_NONSECA_RTC) ? "Non-Secure" : "Secure");
	printf("\n\rEIC: %s", (reg_val & PAC_NONSECA_EIC) ? "Non-Secure" : "Secure");
	printf("\t\tFREQM: %s", (reg_val & PAC_NONSECA_FREQM) ? "Non-Secure" : "Secure");
	printf("\n\rPORT: %s", (reg_val & PAC_NONSECA_PORT) ? "Non-Secure" : "Secure");
	printf("\t\tAC: %s", (reg_val & PAC_NONSECA_AC) ? "Non-Secure" : "Secure");

	reg_val = hri_pac_read_NONSECB_reg(PAC_SEC);

	printf("\n\rIDAU: %s", (reg_val & PAC_NONSECB_IDAU) ? "Non-Secure" : "Secure");
	printf("\t\tDSU: %s", (reg_val & PAC_NONSECB_DSU) ? "Non-Secure" : "Secure");
	printf("\n\rNVMCTRL: %s", (reg_val & PAC_NONSECB_NVMCTRL) ? "Non-Secure" : "Secure");
	printf("\t\tDMAC: %s", (reg_val & PAC_NONSECB_DMAC) ? "Non-Secure" : "Secure");

	reg_val = hri_pac_read_NONSECC_reg(PAC_SEC);

	printf("\n\rEVSYS: %s", (reg_val & PAC_NONSECC_EVSYS) ? "Non-Secure" : "Secure");
	printf("\t\tSERCOM0: %s", (reg_val & PAC_NONSECC_SERCOM0) ? "Non-Secure" : "Secure");
	printf("\n\rSERCOM1: %s", (reg_val & PAC_NONSECC_SERCOM1) ? "Non-Secure" : "Secure");
	printf("\t\tSERCOM2: %s", (reg_val & PAC_NONSECC_SERCOM2) ? "Non-Secure" : "Secure");
	printf("\n\rTC0: %s", (reg_val & PAC_NONSECC_TC0) ? "Non-Secure" : "Secure");
	printf("\t\tTC1: %s", (reg_val & PAC_NONSECC_TC1) ? "Non-Secure" : "Secure");
	printf("\n\rTC2: %s", (reg_val & PAC_NONSECC_TC2) ? "Non-Secure" : "Secure");
	printf("\t\tADC: %s", (reg_val & PAC_NONSECC_ADC) ? "Non-Secure" : "Secure");
	printf("\n\rDAC: %s", (reg_val & PAC_NONSECC_DAC) ? "Non-Secure" : "Secure");
	printf("\t\tPTC: %s", (reg_val & PAC_NONSECC_PTC) ? "Non-Secure" : "Secure");
	printf("\n\rTRNG: %s", (reg_val & PAC_NONSECC_TRNG) ? "Non-Secure" : "Secure");
	printf("\t\tCCL: %s", (reg_val & PAC_NONSECC_CCL) ? "Non-Secure" : "Secure");
	printf("\n\rOPAMP: %s", (reg_val & PAC_NONSECC_OPAMP) ? "Non-Secure" : "Secure");
	printf("\t\tTRAM: %s", (reg_val & PAC_NONSECC_TRAM) ? "Non-Secure" : "Secure");
}

void secure_menu_load_application(void)
{
	ns_funcptr_void NonSecure_ResetHandler;

	/* - Set non-secure main stack (MSP_NS) */
	__TZ_set_MSP_NS(*((uint32_t *)(TZ_START_NS)));

	/* - Get non-secure reset handler (i.e, next word address from TZ_START_NS) */
	NonSecure_ResetHandler = (ns_funcptr_void)(*((uint32_t *)((TZ_START_NS) + 4U)));

	printf(SET_FONT_COLOUR_GREEN);

	/* Start non-secure state software application */
	NonSecure_ResetHandler();
}

void secure_menu_load_malware(void)
{

	/* - Set non-secure main stack (MSP_NS) */

	/* - Get non-secure reset handler (i.e, next word address from TZ_START_NS_MAL) */


	/* Start non-secure state software application */
}

void secure_print_main_menu(void)
{
	printf("\n\n\r----------------------------------------------------------");
	printf("\n\r|           Customer A - Trusted application             |");
	printf("\n\r----------------------------------------------------------");
	printf("\n\n\r    &&&&& &&&&&   &   &  &&&&& &&&&& &&&&&  &&&&");
	printf("\n\r      &   &    &  &   &  &       &   &      &   &");
	printf("\n\r      &   &&&&&   &   &   &&&&   &   &&&&&  &    &");
	printf("\n\r      &   &   &   &   &      &   &   &      &   &");
	printf("\n\r      &   &    &  &&&&&  &&&&    &   &&&&&  &&&&");
	printf("\n\n\r                          &&&&&");
	printf("\n\r                      &&&&&&&&&&&&&");
	printf("\n\r                     &&&&       &&&&");
	printf("\n\r                    &&&           &&&");
	printf("\n\r                    &&&           &&&");
	printf("\n\r                    &&&           &&&");
	printf("\n\r                    &&&           &&&");
	printf("\n\r                   &&&&&&&&&&&&&&&&&&&");
	printf("\n\r                  &&&&&&&&&&&&&&&&&&&&&");
	printf("\n\r                  &&&&&&&&&&&&&&&&&&&&&");
	printf("\n\r                  &&&&&&&&&&&&&&&..&&&&");
	printf("\n\r                  &&&&&&&&&&&&&..&&&&&&");
	printf("\n\r                  &&&&&&..&&&..&&&&&&&&");
	printf("\n\r                  &&&&&&&&...&&&&&&&&&&");
	printf("\n\r                  &&&&&&&&&&&&&&&&&&&&&");
	printf("\n\r                  &&&&&&&&&&&&&&&&&&&&&");
	printf("\n\n\r---------------- Trusted application options --------------");
	printf("\n\n\r0 - Print this menu");
	printf("\n\r1 - Print resources secure allocation");
	printf("\n\r2 - Fill TRAM with secrets ");
	printf("\n\r3 - Print TRAM content ");
	printf("\n\r4 - Fill DataFlash TEROW with secrets ");
	printf("\n\r5 - Print DataFlash TEROW content ");
	printf("\n\n\r---------------- Start Non-Trusted Application ------------");
	printf("\n\n\rS - Start Standard Customer B application ");
	printf("\n\rM - Start  Malware Customer B application ");
	printf("\n\n\r-----------------------------------------------------------");
	printf("\n\rChoice : ");
}

void wdt_message(void)
{
	printf(SET_FONT_COLOUR_GREEN);
	printf(NO_CR_LF);
	printf("\n\r --- WARNING --- WDT DETECTED");
	printf("\n\r - Application in Dead loop ");

	NVIC_DisableIRQ(RTC_IRQn);
	while (1)
		;
}

int main(void)
{
	uint8_t sel, reset_cause;

	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Initialize secure port*/
	port_sec_init();

	/* Initialize dataflash security features */
	secure_dataflash_init();

	/* - Configure Watchdog timer */
	secure_wdt_interrupt_callback_register(wdt_message);
	secure_wdt_init();

	wdt_disable(&WATCHDOG);

	/* - Initialize RTC Tamper */
	secure_rtc_tamper_callback_register(Tamper_Message);

	/* - Initialize PAC security */
	secure_pac_init();

	/* Set print color as green and adjust page */
	printf(SET_FONT_COLOUR_GREEN);
	printf(CLEAR_TERMINAL_WINDOW);

	/* Check reset cause */
	reset_cause = hri_rstc_read_RCAUSE_reg(RSTC);

	if (reset_cause == RSTC_RCAUSE_WDT) {
		printf("\n\r #### Application recovered from Malware ####");
	}

	secure_print_main_menu();

	/* Replace with your application code */
	while (1) {
		sel = getchar();
		switch (sel) {
		case '0':
			printf(CLEAR_TERMINAL_WINDOW);
			secure_print_main_menu();
			break;

		case '1':
			secure_menu_print_fuses_settings();
			break;

		case '2':
			printf("\n\rFill TRAM with secret (0xCAFECAFE) : \n\n\r");
			secure_tram_fill(TRAM_FILL_DATA);
			secure_tram_print();
			break;

		case '3':
			printf("\n\rCurrent TRAM content : \n\n\r");
			secure_tram_print();
			break;

		case '4':
			printf("\n\rFill Dataflash TEROW with secret (0xDECADECA) : \n\n\r");
			secure_dataflash_TEROW_write_pattern(TEROW_WRITE_PATTERN);
			secure_dataflash_print_TEROW();
			break;

		case '5':
			printf("\n\rCurrent Dataflash TEROW content : \n\n\r");
			secure_dataflash_print_TEROW();
			break;

		case 's':
		case 'S':
			secure_menu_load_application();
			break;

		case 'm':
		case 'M':
			/* secure_menu_load_malware(); */
			printf("\n\tNot in Use.\n\n\r");
			break;

		default:
			break;
		}
	}
}
