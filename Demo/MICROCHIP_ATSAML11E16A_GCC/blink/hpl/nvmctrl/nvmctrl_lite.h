
/**
 * \file
 *
 * \brief NVMCTRL related functionality declaration.
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

#ifndef _NVMCTRL_LITE_H_INCLUDED
#define _NVMCTRL_LITE_H_INCLUDED

#include <compiler.h>
#include <utils_assert.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Macro to get fuse value in NVM memory
 *
 * Usage example: NVM_GET_FUSE_VALUE(FUSES_BOD33USERLEVEL);
 *
 * \param  fuse_name fuse to read, normally defined in device header file
 *                   (for example include/component/nvmctrl.h)
 *
 * \return Fuse value.
 */
#define NVM_GET_FUSE_VALUE(fuse_name) ((*((uint32_t *)(fuse_name##_ADDR)) & fuse_name##_Msk) >> fuse_name##_Pos)

/**
 * \brief NVM controller commands.
 */
enum nvm_cmd {
	/** Erase the addressed memory row */
	NVM_CMD_ERASE_ROW = NVMCTRL_CTRLA_CMD_ER,

	/** Write the content of the page buffer to the addressed memory page */
	NVM_CMD_WRITE_PAGE = NVMCTRL_CTRLA_CMD_WP,

	/** Set the Power Reduction Mode */
	NVM_CMD_SET_POWER_REDUCTION_MODE = NVMCTRL_CTRLA_CMD_SPRM,

	/** Clear the Power Reduction Mode */
	NVM_CMD_CLR_POWER_REDUCTION_MODE = NVMCTRL_CTRLA_CMD_CPRM,

	/** Clear the page buffer */
	NVM_CMD_PAGE_BUFFER_CLEAR = NVMCTRL_CTRLA_CMD_PBC,

	/** Invalidate all cache lines */
	NVM_CMD_INVALIDATE_CACHE_LINE = NVMCTRL_CTRLA_CMD_INVALL,
};

/**
 * \brief Initialize NVMCTRL interface
 *
 * \return Initialization status.
 * \retval ERR_NONE         No error.
 * \retval ERR_FAILURE      Initialization fail.
 */
int32_t FLASH_0_init();

/**
 * \brief Execute a command on the NVM controller
 *
 * \param[in] cmd        Command to issue to the NVM controller
 * \param[in] dst_addr   Destination address if the command needs
 *
 * \return Status of the result to execute a command.
 * \retval ERR_NONE         No error.
 * \retval ERR_INVALID_ARG  Invalid argument.
 * \retval ERR_FAILURE      Command fail.
 */
int32_t FLASH_0_exec_cmd(const enum nvm_cmd cmd, uint32_t dst_addr);

/**
 * \brief Erase a row in NVM memory
 *
 * \param[in]  dst_addr      Destination address in a row to erase
 *
 * \return Erase row status.
 * \retval ERR_NONE         No error.
 * \retval ERR_INVALID_ARG  Invalid argument.
 * \retval ERR_FAILURE      Erase fail.
 */
int32_t FLASH_0_erase_row(const uint32_t dst_addr);

/**
 * \brief Write a page buffer in NVM memory
 *
 * \note If writing to a page that has previously been written to, the page's
 *       row should be erased before attempting to write new data to the page.
 *
 * \note If manual write mode is enabled, the write command must be executed after
 * this function, otherwise the data will not write to NVM from page buffer.
 *
 * \param[in]  dst_addr      Destination page address to write
 * \param[in]  buffer        Pointer to buffer where the data to
 *                           write is stored
 * \param[in] length         The size of data to write to a page
 *
 * \return Write page status.
 * \retval ERR_NONE         No error.
 * \retval ERR_INVALID_ARG  Invalid argument.
 * \retval ERR_FAILURE      Operation fail.
 */
int32_t FLASH_0_write_page_buffer(const uint32_t dst_addr, const uint8_t *buffer, const uint16_t length);

/**
 * \brief Write (program) a page in NVM memory
 *
 * \note If writing to a page that has previously been written to, the page's
 *       row should be erased before attempting to write new data to the page.
 *
 * \param[in]  dst_addr      Destination page address to write
 * \param[in]  buffer        Pointer to buffer where the data to
 *                           write is stored
 * \param[in] length         The size of data to write to a page
 *
 * \return Write page status.
 * \retval ERR_NONE         No error.
 * \retval ERR_INVALID_ARG  Invalid argument.
 * \retval ERR_FAILURE      Operation fail.
 */
int32_t FLASH_0_write_page(const uint32_t dst_addr, const uint8_t *buffer, const uint16_t length);

/**
 * \brief Read a number of bytes from a page in the NVM memory
 *
 * \param[in]  src_addr  Source bytes address (page address aligned) to read from flash
 * \param[out] buffer    Pointer to a buffer where the content
 *                       of the read pages will be stored
 * \param[in]  length    Number of bytes to read
 *
 * \return Read status.
 * \retval ERR_NONE         No error.
 * \retval ERR_INVALID_ARG  Invalid argument.
 * \retval ERR_FAILURE      Operation fail.
 */
int32_t FLASH_0_read(uint32_t src_addr, uint8_t *buffer, uint32_t length);

#ifdef __cplusplus
}
#endif

#endif /* _NVMCTRL_LITE_H_INCLUDED */
