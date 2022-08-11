/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2022 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: MUG51 Read UID demo code
//***********************************************************************************************************
#include "MUG51.h"

/* For printf code only. Disable this define to reduce code size. */
#define print_function 

/**********************************/
/* *only read one byte of UID    */
/*********************************/ 

void main(void)
{
  unsigned char READ;

#ifdef print_function  
    Enable_P31_UART0_VCOM_115200_printf();
#endif  
 
  UID_Read();
#ifdef print_function
  /*printf must in SFR page 0 */
    _push_(SFRS);
    SFRS = 0; printf ("\n UID = ");
    for(READ=0;READ<12;READ++)
    {
      printf (" 0x%bx",UIDBuffer[READ]);
    }
    _pop_(SFRS);
#endif
  while(1);


}