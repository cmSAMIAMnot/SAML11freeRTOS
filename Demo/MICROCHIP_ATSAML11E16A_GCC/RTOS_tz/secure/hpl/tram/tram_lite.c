
/**
 * \file
 *
 * \brief TRAM related functionality implementation.
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

#include "tram_lite.h"

/**
 * \brief Initialize TRAM interface
 */
int32_t TRUST_RAM_init()
{
	if (!hri_tram_is_syncing(TRAM, TRAM_SYNCBUSY_SWRST)) {
		if (hri_tram_get_CTRLA_reg(TRAM, TRAM_CTRLA_ENABLE)) {
			hri_tram_clear_CTRLA_ENABLE_bit(TRAM);
			hri_tram_wait_for_sync(TRAM, TRAM_SYNCBUSY_ENABLE);
		}
		hri_tram_write_CTRLA_reg(TRAM, TRAM_CTRLA_SWRST);
	}
	hri_tram_wait_for_sync(TRAM, TRAM_SYNCBUSY_SWRST);

	// hri_tram_write_CTRLA_reg(TRAM, 0 << TRAM_CTRLA_SILACC_Pos /* Setting: disabled */
	//		 | 0 << TRAM_CTRLA_DRP_Pos /* Setting: disabled */
	//		 | 0 << TRAM_CTRLA_TAMPERS_Pos); /* Setting: disabled */

	// hri_tram_write_INTEN_reg(TRAM, 0 << TRAM_INTENSET_DRP_Pos /* Setting: disabled */
	//		 | 0 << TRAM_INTENSET_ERR_Pos); /* Setting: disabled */

	// hri_tram_write_DSCC_reg(TRAM, 0x0 << TRAM_DSCC_DSCKEY_Pos /* Setting: 0x0 */
	//		 | 0 << TRAM_DSCC_DSCEN_Pos); /* Setting: disabled */

	// hri_tram_write_PERMW_reg(TRAM, 0x0 << TRAM_PERMW_DATA_Pos); /* Setting: 0x0 */

	hri_tram_write_CTRLA_ENABLE_bit(TRAM, 1 << TRAM_CTRLA_ENABLE_Pos); /* Setting: enabled */

	return ERR_NONE;
}

/**
 * \brief Read security RAM n
 */
uint32_t TRUST_RAM_read(uint32_t index)
{
	return hri_tram_read_RAM_reg(TRAM, index);
}

/**
 * \brief Write security RAM n
 */
void TRUST_RAM_write(uint32_t index, uint32_t data)
{
	hri_tram_write_RAM_reg(TRAM, index, data);
}
