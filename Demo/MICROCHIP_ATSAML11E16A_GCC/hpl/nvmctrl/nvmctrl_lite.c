
/**
 * \file
 *
 * \brief NVMCTRL related functionality implementation.
 *
 * Copyright (c) 2017 Microchip Technology Inc. and its subsidiaries.
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
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
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

#include "nvmctrl_lite.h"

#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
#define _NVMCTRL NVMCTRL_SEC
#else
#define _NVMCTRL NVMCTRL
#endif

/**
 * \internal Pointer to the NVM MEMORY region start address
 */
#define NVM_MEMORY ((volatile uint16_t *)FLASH_ADDR)

static inline void _nvmctrl_write_CTRLB_reg(const void *const hw, uint32_t data)
{
	data |= hri_nvmctrl_get_CTRLB_reg(hw, NVMCTRL_CTRLB_RWS_Msk);
	hri_nvmctrl_write_CTRLB_reg(hw, data);
}

static inline void _nvmctrl_write_SECCTRL_reg(const void *const hw, uint32_t data)
{
	hri_nvmctrl_write_SECCTRL_reg(hw, data | NVMCTRL_SECCTRL_KEY_KEY);
}

/**
 * \brief Initialize NVMCTRL interface
 */
int32_t FLASH_0_init()
{
	// _nvmctrl_write_CTRLB_reg( _NVMCTRL , 0 << NVMCTRL_CTRLB_FWUP_Pos /* Setting: disabled */
	//		 | 0 << NVMCTRL_CTRLB_SLEEPPRM_Pos /* Setting: disabled */
	//		 | 0 << NVMCTRL_CTRLB_QWEN_Pos /* Setting: disabled */
	//		 | 0 << NVMCTRL_CTRLB_CACHEDIS_Pos /* Setting: disabled */
	//		 | 0 << NVMCTRL_CTRLB_READMODE_Pos); /* Setting: 0 */

	// hri_nvmctrl_write_CTRLC_reg( _NVMCTRL , 1 << NVMCTRL_CTRLC_MANW_Pos); /* Setting: enabled */

	// hri_nvmctrl_write_EVCTRL_reg( _NVMCTRL , 0 << NVMCTRL_EVCTRL_AUTOWEI_Pos /* Setting: disabled */
	//		 | 0 << NVMCTRL_EVCTRL_AUTOWINV_Pos); /* Setting: disabled */

	// hri_nvmctrl_write_DSCC_reg( _NVMCTRL , 0x0 << NVMCTRL_DSCC_DSCKEY_Pos); /* Setting: 0x0 */

	// _nvmctrl_write_SECCTRL_reg( _NVMCTRL , 0x0 << NVMCTRL_SECCTRL_TEROW_Pos /* Setting: 0x0 */
	//		 | 0 << NVMCTRL_SECCTRL_DSCEN_Pos /* Setting: disabled */
	//		 | 0 << NVMCTRL_SECCTRL_SILACC_Pos /* Setting: disabled */
	//		 | 0 << NVMCTRL_SECCTRL_TAMPEEN_Pos); /* Setting: disabled */

	return ERR_NONE;
}

/**
 * \brief Execute a command on the NVM controller
 */
int32_t FLASH_0_exec_cmd(const enum nvm_cmd cmd, uint32_t dst_addr)
{
	/* Wait until this module isn't busy */
	while (!hri_nvmctrl_get_STATUS_READY_bit(_NVMCTRL)) {
	}

	/* Clear flags */
	hri_nvmctrl_clear_INTFLAG_reg(_NVMCTRL, NVMCTRL_INTFLAG_MASK);

	/* Commands requiring address */
	if ((cmd == NVM_CMD_ERASE_ROW) || (cmd == NVM_CMD_WRITE_PAGE)) {
		hri_nvmctrl_write_ADDR_reg(_NVMCTRL, dst_addr);
	}

	/* Set command */
	hri_nvmctrl_write_CTRLA_reg(_NVMCTRL, cmd | NVMCTRL_CTRLA_CMDEX_KEY);

	/* Wait until the command done */
	while (!hri_nvmctrl_get_interrupt_DONE_bit(_NVMCTRL)) {
		/* Check if there is error in NVM erase operation */
		if (hri_nvmctrl_get_INTFLAG_reg(
		        _NVMCTRL, NVMCTRL_INTFLAG_LOCKE | NVMCTRL_INTFLAG_NVME | NVMCTRL_INTFLAG_PROGE | NVMCTRL_INTFLAG_KEYE)
		    != 0) {
			return ERR_FAILURE;
		}
	}

	return ERR_NONE;
}

/**
 * \brief Erase a row in NVM memory
 */
int32_t FLASH_0_erase_row(const uint32_t dst_addr)
{
	return FLASH_0_exec_cmd(NVM_CMD_ERASE_ROW, dst_addr);
}

/**
 * \brief Write a page buffer in NVM memory
 */
int32_t FLASH_0_write_page_buffer(const uint32_t dst_addr, const uint8_t *buffer, const uint16_t length)
{
	/* Check if the write address not aligned to the start of a page */
	if (dst_addr & (NVMCTRL_PAGE_SIZE - 1)) {
		return ERR_INVALID_ARG;
	}

	/* Check if the write length is longer than an NVM page */
	if (length > NVMCTRL_PAGE_SIZE) {
		return ERR_INVALID_ARG;
	}

	/* Erase the page buffer before buffering new data */
	FLASH_0_exec_cmd(NVM_CMD_PAGE_BUFFER_CLEAR, dst_addr);

	uint32_t nvm_addr = dst_addr / 2;
	/* NVM _must_ be accessed as a series of 16-bit words, perform manual copy
	 * to ensure alignment */
	for (uint16_t i = 0; i < length; i += 2) {
		uint16_t data;

		data = buffer[i];
		if (i < (length - 1)) {
			data |= (buffer[i + 1] << 8);
		}
		NVM_MEMORY[nvm_addr++] = data;
	}

	return ERR_NONE;
}

/**
 * \brief Write (program) a page in NVM memory
 */
int32_t FLASH_0_write_page(const uint32_t dst_addr, const uint8_t *buffer, const uint16_t length)
{
	int32_t rc = ERR_NONE;

	rc = FLASH_0_write_page_buffer(dst_addr, buffer, length);
	if (rc != ERR_NONE) {
		return rc;
	} else {
		/* Execute NVM write page command */
		if ((hri_nvmctrl_get_CTRLC_MANW_bit(_NVMCTRL) == 1) || (length < NVMCTRL_PAGE_SIZE)) {
			rc = FLASH_0_exec_cmd(NVM_CMD_WRITE_PAGE, dst_addr);
		}
	}

	return rc;
}

/**
 * \brief Read a number of bytes from a page in the NVM memory
 */
int32_t FLASH_0_read(uint32_t src_addr, uint8_t *buffer, uint32_t length)
{
	uint32_t nvm_addr = src_addr / 2;
	uint32_t i;
	uint16_t data;

	/* Wait until this module isn't busy */
	while (!hri_nvmctrl_get_STATUS_READY_bit(_NVMCTRL)) {
	}

	/* Check whether byte address is word-aligned*/
	if (src_addr % 2) {
		data      = NVM_MEMORY[nvm_addr++];
		buffer[0] = data >> 8;
		i         = 1;
	} else {
		i = 0;
	}

	/* NVM _must_ be accessed as a series of 16-bit words, perform manual copy
	 * to ensure alignment */
	while (i < length) {
		data      = NVM_MEMORY[nvm_addr++];
		buffer[i] = (data & 0xFF);
		if (i < (length - 1)) {
			buffer[i + 1] = (data >> 8);
		}
		i += 2;
	}

	return ERR_NONE;
}
