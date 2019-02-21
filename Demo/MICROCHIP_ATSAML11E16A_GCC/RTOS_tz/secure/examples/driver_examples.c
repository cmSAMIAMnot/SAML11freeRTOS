/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

#ifndef NVMCTRL_ROW_SIZE
#define NVMCTRL_ROW_SIZE (NVMCTRL_PAGE_SIZE * NVMCTRL_ROW_PAGES)
#endif
static uint8_t flash_src_data[FLASH_PAGE_SIZE];
static uint8_t flash_chk_data[FLASH_PAGE_SIZE];

/**
 * Example of using FLASH to read and write buffer.
 */
void FLASH_example(void)
{
	uint32_t i;

	/* Target address.
	 * Make sure the address is reasonable to your application.
	 * It might a address in NVM memory of FLASH, DATAFLASH, AUX FLASH.
	 */
	uint32_t target_addr = FLASH_ADDR + FLASH_SIZE - NVMCTRL_ROW_SIZE;

	/* Initialize source data */
	for (i = 0; i < FLASH_PAGE_SIZE; i++) {
		flash_src_data[i] = i;
	}

	/* Erase row in flash */
	FLASH_erase_row(target_addr);

	/* Write data to flash */
	FLASH_write_page(target_addr, flash_src_data, FLASH_PAGE_SIZE);

	/* Read data from flash */
	FLASH_read(target_addr, flash_chk_data, FLASH_PAGE_SIZE);

	/* Check data */
	for (i = 0; i < FLASH_PAGE_SIZE; i++) {
		if (flash_src_data[i] != flash_chk_data[i]) {
			while (1)
				; /* Error happen */
		}
	}
}

/**
 * Lock GCLK.
 */
void pac_example(void)
{
	bool stat;

	periph_get_lock_state(GCLK, &stat);
	if (!stat) {
		periph_lock(GCLK);
	}
}

/**
 * Example of using UART_INSTANCE to write "Hello World" using the IO abstraction.
 */
void UART_INSTANCE_example(void)
{
	struct io_descriptor *io;
	usart_sync_get_io_descriptor(&UART_INSTANCE, &io);
	usart_sync_enable(&UART_INSTANCE);

	io_write(io, (uint8_t *)"Hello World!", 12);
}

void I2C_INSTANCE_example(void)
{
	struct io_descriptor *I2C_INSTANCE_io;

	i2c_m_sync_get_io_descriptor(&I2C_INSTANCE, &I2C_INSTANCE_io);
	i2c_m_sync_enable(&I2C_INSTANCE);
	i2c_m_sync_set_slaveaddr(&I2C_INSTANCE, 0x12, I2C_M_SEVEN);
	io_write(I2C_INSTANCE_io, (uint8_t *)"Hello World!", 12);
}

/**
 * Example of using TRUST_RAM to read and write security RAM.
 */
void TRUST_RAM_example(void)
{
	uint32_t i;
	uint32_t tram_src_data[3] = {0x12345678, 0xAABBCCDD, 0x55AAABCD};
	uint32_t tram_chk_data[3];

	/* Write data to TRAM */
	for (i = 0; i < 3; i++) {
		TRUST_RAM_write(i, tram_src_data[i]);
	}

	/* Read data from TRAM */
	for (i = 0; i < 3; i++) {
		tram_chk_data[i] = TRUST_RAM_read(i);
	}

	/* Check data */
	for (i = 0; i < 3; i++) {
		if (tram_src_data[i] != tram_chk_data[i]) {
			while (1)
				; /* Error happen */
		}
	}
}

/**
 * Example of using WATCHDOG.
 */
void WATCHDOG_example(void)
{
	uint32_t clk_rate;
	uint16_t timeout_period;

	clk_rate       = 1000;
	timeout_period = 4096;
	wdt_set_timeout_period(&WATCHDOG, clk_rate, timeout_period);
	wdt_enable(&WATCHDOG);
}
