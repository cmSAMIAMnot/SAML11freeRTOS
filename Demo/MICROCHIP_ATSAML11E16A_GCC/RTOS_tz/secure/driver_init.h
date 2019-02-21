/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef DRIVER_INIT_INCLUDED
#define DRIVER_INIT_INCLUDED

#include "atmel_start_pins.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <hal_atomic.h>
#include <hal_delay.h>
#include <hal_gpio.h>
#include <hal_init.h>
#include <hal_io.h>
#include <hal_sleep.h>
#include <hpl_crya.h>

#include <nvmctrl_lite.h>

#include <hal_pac.h>
#include <rtc_lite.h>

#include <hal_usart_sync.h>

#include <hal_i2c_m_sync.h>
#include <tram_lite.h>

#include <hal_wdt.h>

extern struct usart_sync_descriptor UART_INSTANCE;

extern struct i2c_m_sync_desc I2C_INSTANCE;

extern struct wdt_descriptor WATCHDOG;

void    FLASH_CLOCK_init(void);
int32_t FLASH_init(void);

void   REAL_TIMER_COUNTER_CLOCK_init(void);
int8_t REAL_TIMER_COUNTER_init(void);

void UART_INSTANCE_PORT_init(void);
void UART_INSTANCE_CLOCK_init(void);
void UART_INSTANCE_init(void);

void I2C_INSTANCE_CLOCK_init(void);
void I2C_INSTANCE_init(void);
void I2C_INSTANCE_PORT_init(void);

void    TRUST_RAM_CLOCK_init(void);
int32_t TRUST_RAM_init(void);

void WATCHDOG_CLOCK_init(void);
void WATCHDOG_init(void);

/**
 * \brief Perform system initialization, initialize pins and clocks for
 * peripherals
 */
void system_init(void);

#ifdef __cplusplus
}
#endif
#endif // DRIVER_INIT_INCLUDED
