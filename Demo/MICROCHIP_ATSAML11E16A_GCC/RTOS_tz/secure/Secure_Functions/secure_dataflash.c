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

/* Header file with secure interface API */
#include "secure_dataflash.h"

volatile uint32_t *DATA32 = (uint32_t *)NVMCTRL_DATAFLASH;
#define NVMCTRL_DATAFLASH_SIZE 2048

/**
 * \internal Pointer to the DATAFLASH MEMORY region start address
 */
#define NVM_MEMORY ((volatile uint32_t *)FLASH_ADDR)

void secure_dataflash_init(void)
{
	/* Enable security features of Dataflash */
	hri_nvmctrl_write_SECCTRL_reg(
	    NVMCTRL_SEC,
	    (NVMCTRL_SECCTRL_KEY(NVMCTRL_SECCTRL_KEY_KEY_Val) | NVMCTRL_SECCTRL_TEROW(0) | NVMCTRL_SECCTRL_TAMPEEN));

	/* Enable Automatic write */
	hri_nvmctrl_clear_CTRLC_MANW_bit(NVMCTRL_SEC);
}

void secure_dataflash_TEROW_write_pattern(uint32_t pattern)
{
	/* Erase Row */
	FLASH_erase_row((uint32_t)&DATA32[0]);

	/* Page Buffer Clear */
	FLASH_exec_cmd(NVM_CMD_PAGE_BUFFER_CLEAR, (uint32_t)NULL);

	/* Fill row with pattern */
	for (uint32_t data = 0; data < 32; data++) {
		DATA32[data] = pattern;
	}
}

void secure_dataflash_print_TEROW(void)
{
	uint32_t *address = (uint32_t *)DATAFLASH_ADDR;

	for (uint32_t i = 0; i < DATAFLASH_NB_OF_PAGES; i++) {
		if (i % 2 == 0) {
			printf("\r\n 0x%08X : ", (unsigned int)&(address[0 + i]));
		}
		printf("%08X ", (unsigned int)address[i]);
	}
}
