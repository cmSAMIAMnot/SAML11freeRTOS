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

#ifndef APP_VENEER_H_
#define APP_VENEER_H_

#include "sam.h"

/* define secure callback type for function with void parameter and void return  */
typedef void (*secure_void_cb_t)(void);

/* *********** Secure Console NSC functions *********** */

/* ------------------------------------------------------
- NAME :		void nsc_puts(uint8_t * string);
- DESCRIPTION : (Secure Gateway) Print red string on secure console
- PARAMETERS :	uint8_t* string : string to be displayed
- RETURN :		None
------------------------------------------------------ */
void nsc_puts(uint8_t *string);

/* ------------------------------------------------------
- NAME :		void nsc_putc(uint8_t c);
- DESCRIPTION : (Secure Gateway) Print red character on console
- PARAMETERS :	uint8_t c : Character to be displayed
- RETURN :		None
------------------------------------------------------ */
void nsc_putc(uint8_t c);

/* ------------------------------------------------------
- NAME :		void nsc_putc(uint8_t c);
- DESCRIPTION : (Secure Gateway) Print red character on console
- PARAMETERS :	uint8_t c : Character to be displayed
- RETURN :		None
------------------------------------------------------ */
uint8_t nsc_getc(void);

/* ***********   Secure LED NSC functions   *********** */

/* ------------------------------------------------------
- NAME :		void nsc_led_on(void);
- DESCRIPTION : (Secure Gateway) Light on the secure LED from I/O1 extension
- PARAMETERS :	None
- RETURN :		None
------------------------------------------------------ */
void nsc_led_on(void);

/* ------------------------------------------------------
- NAME :		void nsc_led_off(void);
- DESCRIPTION : (Secure Gateway) Light off the secure LED from I/O1 extension
- PARAMETERS :	None
- RETURN :		None
------------------------------------------------------ */
void nsc_led_off(void);

/* ------------------------------------------------------
- NAME :		void nsc_led_toggle(void);
- DESCRIPTION : (Secure Gateway) Toggle the secure LED from I/O1 extension
- PARAMETERS :	None
- RETURN :		None
------------------------------------------------------ */
void nsc_led_toggle(void);

/* ***********   Secure LED NSC functions   *********** */

/* ------------------------------------------------------
- NAME :		void nsc_enter_standby_mode(void);
- DESCRIPTION : (Secure Gateway) Request system to enter low-power standby mode
- PARAMETERS :	None
- RETURN :		None
------------------------------------------------------ */
void nsc_enter_standby_mode(void);

/* ***********   Secure RTC NSC functions   *********** */

/* ------------------------------------------------------
- NAME :		void nsc_rtc_enable_CMP0_interrupt (void);
- DESCRIPTION : (Secure Gateway) Enable secure RTC CMP0 interrupt
- PARAMETERS :	None
- RETURN :		None
------------------------------------------------------ */
void nsc_rtc_enable_CMP0_interrupt(void);

/* ------------------------------------------------------
- NAME :		void nsc_rtc_CMP0_val_set (uint32_t cmp0_val);
- DESCRIPTION : (Secure Gateway) Set secure RTC CMP0 value
- PARAMETERS :	uint32_t cmp0_val : value to be set in secure RTC CMP0 register
- RETURN :		None
------------------------------------------------------ */
void nsc_rtc_CMP0_val_set(uint32_t cmp0_val);

/* ------------------------------------------------------
- NAME :		void nsc_rtc_CMP0_callback_register (uint32_t cmp0_val);
- DESCRIPTION : (Secure Gateway) register callback function to be executed
                on secure RTC CMP0 interrupt detection
- PARAMETERS :	secure_void_cb_t pfunction : pointer to void xxx(void) function
- RETURN :		None
------------------------------------------------------ */
void nsc_rtc_CMP0_callback_register(secure_void_cb_t pfunction);

/* --------- Secure Temp sensor NSC functions --------------- */

#endif /* APP_VENEER_H_ */
