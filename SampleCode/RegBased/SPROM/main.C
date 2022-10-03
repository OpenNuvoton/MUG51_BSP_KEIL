/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2022 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: MUG51 locate data in APROM simple demo 
//***********************************************************************************************************
#include "MUG51.h"
#include "SPROM.h"



void main (void) 
{
    Enable_P31_UART0_VCOM_115200_printf();

    set_IAPUEN_SPMEN;             //Enable SPROM memory mapping only for check SPROM in memory window

    while(1)
    {
      SPROM_CODE();
      printf ("\n SPTEMP= 0x%BX", SPTEMP);
      Timer0_Delay1ms(300);
    }

}
