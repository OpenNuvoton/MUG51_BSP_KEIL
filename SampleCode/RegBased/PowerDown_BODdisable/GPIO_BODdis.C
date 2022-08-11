/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2022 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: MS51 power down code for test power down current, BOD disabled.
//***********************************************************************************************************
#include "MUG51.h"


void main (void) 
{
  unsigned char i;
/*Quasi mode better for power down power comsuption */  
    ALL_GPIO_QUASI_MODE;
/* clock only for reference, real chip please don't output clock*/  

/*MUST DISABLE BOD to low power */
//    DISABLE_BOD;              //BOD enable power down current please check datasheet DC charactor.

//    while(P01);
//    CKDIV = 0;
while(1)
//    for (i=0;i<0x05;i++)
    {
      P10 = ~P10;
//      Timer0_Delay1ms(200);
delay;
    }

//    P0=0;
//    P1=0;
//    P2=0;
//    P3=0;
/* Real into power down mode */
//    set_CKCON_CLOEN;
//    SFRS=1;CKDIV=12;
//    set_PCON_PD;
    while(1);  
  
}



