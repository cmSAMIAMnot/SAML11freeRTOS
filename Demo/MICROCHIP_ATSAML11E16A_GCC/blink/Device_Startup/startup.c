/**
*
* \brief Secure UART bootloader for SAM L11
*
* Copyright (c) 2018 Microchip Technology Inc.
*
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License"); you may
* not use this file except in compliance with the License.
* You may obtain a copy of the Licence at
* 
 * http://www.apache.org/licenses/LICENSE-2.0
* 
 * Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an AS IS BASIS, WITHOUT
* WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

//-----------------------------------------------------------------------------
void irq_handler_reset(void);

extern int main(void);

extern void _stack_top(void);
extern unsigned int _sfixed;
extern unsigned int _etext;
extern unsigned int _data;
extern unsigned int _edata;
extern unsigned int _bss;
extern unsigned int _ebss;
#define SCB_VTOR *(uint32_t volitile*)0xE000ED08

//-----------------------------------------------------------------------------
__attribute__ ((used, section(".vectors")))
void (* const vectors[])(void) =
{
  &_stack_top,
  irq_handler_reset,
};

//-----------------------------------------------------------------------------
__attribute__ ((noinline, section(".romfunc")))
void irq_handler_reset(void)
{
  unsigned int *src, *dst;

  src = &_etext;
  dst = &_data;
  while (dst < &_edata)
    *dst++ = *src++;

  dst = &_bss;
  while (dst < &_ebss)
    *dst++ = 0;

	/* update the vtabl pointer for the rom offset */
  dst = (uint32_t *)&_sfixed;
  /*SCB->VTOR = ((uint32_t)dst & SCB_VTOR_TBOFF_Msk);*/
  SCB_VTOR = ((uint32_t)dst + 4U);

  main();
}
