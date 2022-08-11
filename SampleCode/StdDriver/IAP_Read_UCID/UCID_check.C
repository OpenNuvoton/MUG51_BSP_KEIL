/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2022 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: MlL51 read UCID demo
//***********************************************************************************************************
#include "MUG51.h"

#define FSYSCLK  7372800
/* For printf code only. Disable this define to reduce code size. */
#define print_function 

/***********************/
/* main loop            */
/***********************/ 
void main(void)
{
    unsigned char i;
#ifdef print_function  
/* Initial UART0 for printf */
    Enable_P31_UART0_VCOM_115200_printf();
#endif
  
    UCID_Read();
#ifdef print_function
    /*printf must in SFR page 0 */
    _push_(SFRS);
    SFRS = 0;  
    printf ("\n UCID = ");
    for(i=0;i<16;i++)
    { 
       printf (" 0x%bx",UCIDBuffer[i]);
    }
    _pop_(SFRS);    
 #endif 
  while(1);


}