/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>

#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE != 3U))
/* Weak Non-secure callable function. Real one should be in secure gateway library. */
WEAK int32_t nsc_periph_clock_init(uint32_t gclk_id, uint32_t gclk_src)
{
	(void)gclk_id;
	(void)gclk_src;
	return 0;
}
#endif

struct usart_sync_descriptor UART_INSTANCE;

struct i2c_m_sync_desc I2C_INSTANCE;

struct wdt_descriptor WATCHDOG;

/**
 * \brief NVMCTRL initialization function
 *
 * Enables NVMCTRL peripheral, clocks and initializes driver
 */
void FLASH_clock_init(void)
{
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U))
	hri_mclk_set_AHBMASK_NVMCTRL_bit(MCLK);
	hri_mclk_set_APBBMASK_NVMCTRL_bit(MCLK);
#endif
}

/**
 * \brief Rtc initialization function
 *
 * Enables Rtc peripheral, clocks and initializes driver
 */
void REAL_TIMER_COUNTER_CLOCK_init(void)
{
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U))
	hri_mclk_set_APBAMASK_RTC_bit(MCLK);
#endif
}

void UART_INSTANCE_PORT_init(void)
{

	gpio_set_pin_function(STDIO_TXD_PIN, PINMUX_PA24C_SERCOM0_PAD2);

	gpio_set_pin_function(STDIO_RXD_PIN, PINMUX_PA25C_SERCOM0_PAD3);
}

void UART_INSTANCE_CLOCK_init(void)
{
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U))
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM0_GCLK_ID_CORE, CONF_GCLK_SERCOM0_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM0_GCLK_ID_SLOW, CONF_GCLK_SERCOM0_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_mclk_set_APBCMASK_SERCOM0_bit(MCLK);
#else
	nsc_periph_clock_init(SERCOM0_GCLK_ID_CORE, CONF_GCLK_SERCOM0_CORE_SRC);
	nsc_periph_clock_init(SERCOM0_GCLK_ID_SLOW, CONF_GCLK_SERCOM0_SLOW_SRC);
#endif
}

void UART_INSTANCE_init(void)
{
	UART_INSTANCE_CLOCK_init();
	usart_sync_init(&UART_INSTANCE, SERCOM0, (void *)NULL);
	UART_INSTANCE_PORT_init();
}

void I2C_INSTANCE_PORT_init(void)
{

	gpio_set_pin_pull_mode(I2C_SDA_PIN,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(I2C_SDA_PIN, PINMUX_PA16C_SERCOM1_PAD0);

	gpio_set_pin_pull_mode(I2C_SCL_PIN,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(I2C_SCL_PIN, PINMUX_PA17C_SERCOM1_PAD1);
}

void I2C_INSTANCE_CLOCK_init(void)
{
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U))
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM1_GCLK_ID_CORE, CONF_GCLK_SERCOM1_CORE_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_gclk_write_PCHCTRL_reg(GCLK, SERCOM1_GCLK_ID_SLOW, CONF_GCLK_SERCOM1_SLOW_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
	hri_mclk_set_APBCMASK_SERCOM1_bit(MCLK);
#else
	nsc_periph_clock_init(SERCOM1_GCLK_ID_CORE, CONF_GCLK_SERCOM1_CORE_SRC);
	nsc_periph_clock_init(SERCOM1_GCLK_ID_SLOW, CONF_GCLK_SERCOM1_SLOW_SRC);
#endif
}

void I2C_INSTANCE_init(void)
{
	I2C_INSTANCE_CLOCK_init();
	i2c_m_sync_init(&I2C_INSTANCE, SERCOM1);
	I2C_INSTANCE_PORT_init();
}

/**
 * \brief TRAM initialization function
 *
 * Enables TRAM peripheral, clocks and initializes driver
 */
void TRUST_RAM_CLOCK_init(void)
{
	hri_mclk_set_AHBMASK_TRAM_bit(MCLK);
}

void WATCHDOG_CLOCK_init(void)
{
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U))
	hri_mclk_set_APBAMASK_WDT_bit(MCLK);
#endif
}

void WATCHDOG_init(void)
{
	WATCHDOG_CLOCK_init();
	wdt_init(&WATCHDOG, WDT);
}

void system_init(void)
{
#if (defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U))
	/* Only initialize MCU clock when the project is TrustZone secure project  */
	init_mcu();
#endif

	// GPIO on PA08

	gpio_set_pin_direction(TAMPER_IN_PIN,
	                       // <y> Pin direction
	                       // <id> pad_direction
	                       // <GPIO_DIRECTION_OFF"> Off
	                       // <GPIO_DIRECTION_IN"> In
	                       // <GPIO_DIRECTION_OUT"> Out
	                       GPIO_DIRECTION_IN);

	gpio_set_pin_level(TAMPER_IN_PIN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	gpio_set_pin_pull_mode(TAMPER_IN_PIN,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(TAMPER_IN_PIN,
	                      // <y> Pin function
	                      // <id> pad_function
	                      // <i> Auto : use driver pinmux if signal is imported by driver, else turn off function
	                      // <GPIO_PIN_FUNCTION_OFF"> Auto
	                      // <GPIO_PIN_FUNCTION_OFF"> Off
	                      // <GPIO_PIN_FUNCTION_A"> A
	                      // <GPIO_PIN_FUNCTION_B"> B
	                      // <GPIO_PIN_FUNCTION_C"> C
	                      // <GPIO_PIN_FUNCTION_D"> D
	                      // <GPIO_PIN_FUNCTION_E"> E
	                      // <GPIO_PIN_FUNCTION_F"> F
	                      // <GPIO_PIN_FUNCTION_G"> G
	                      // <GPIO_PIN_FUNCTION_H"> H
	                      // <GPIO_PIN_FUNCTION_I"> I
	                      GPIO_PIN_FUNCTION_I);

	// GPIO on PA09

	gpio_set_pin_level(TAMPER_0V,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(TAMPER_0V, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(TAMPER_0V, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA18

	gpio_set_pin_level(LED0,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(LED0, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED0, GPIO_PIN_FUNCTION_OFF);

	FLASH_clock_init();
	FLASH_init();

	REAL_TIMER_COUNTER_CLOCK_init();
	REAL_TIMER_COUNTER_init();

	UART_INSTANCE_init();

	I2C_INSTANCE_init();

	TRUST_RAM_CLOCK_init();
	TRUST_RAM_init();

	WATCHDOG_init();
}
