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

#include "Secure_Functions/secure_temp_sensor.h"
#include "main.h"

static struct at30tse75x   AT30TSE75X_descr;
struct temperature_sensor *AT30TSE75X;

void secure_temp_sensor_init(void)
{
	/* - Initialize I/O1 Temperature sensor driver */
	i2c_m_sync_enable(&I2C_INSTANCE);
	AT30TSE75X = at30tse75x_construct(&AT30TSE75X_descr.parent, &I2C_INSTANCE, CONF_T30TSE75X_RESOLUTION);
}

float secure_temperature_sensor_read(void)
{
	printf(SET_FONT_COLOUR_GREEN);
	printf("temperature_sensor_read(AT30TSE75X)");
	return temperature_sensor_read(AT30TSE75X);
	printf(SET_FONT_COLOUR_RED);
}

void secure_temp_sensor_enable(void)
{
	i2c_m_sync_enable(&I2C_INSTANCE);
}

void secure_temp_sensor_disable(void)
{
	i2c_m_sync_disable(&I2C_INSTANCE);
}
