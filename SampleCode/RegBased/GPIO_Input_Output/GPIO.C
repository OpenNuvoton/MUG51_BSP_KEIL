/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2022 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: MUG51 GPIO toggle demo code
//***********************************************************************************************************
#include "MUG51.h"

unsigned char temp _at_ 0x08;
unsigned char idata itemp _at_ 0x90;
unsigned char xdata xtemp _at_ 0x80;

//----------------------------------------------------------------------------------------------//
void main (void)
{
/* As defaut all multi function define as GPIO */ 
  ALL_GPIO_PUSHPULL_MODE;
  while(1)
  {
    P0 = ~P0;
    P1 = ~P1;
    P2 = ~P2;
    P3 = ~P3;
    P4 = ~P4;
    P5 = ~P5;
    SFRS = 2;
//    P6 = ~P6;
    Timer2_Delay1ms(1);
  }
}



