/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2022 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: MUG51 INT0 pin demo 
//***********************************************************************************************************
#include "MUG51.h"

/* IMPORTANT !! This define for printf code only. Disable this define to reduce code size. */
#define print_function

bit  int0flag = 0;
/* External pin interrupt INT0 subroutine */
void INT0_ISR (void) interrupt 0          // Vector @  0x03
{
    _push_(SFRS);

    clr_TCON_IE0;          //clr int flag wait next falling edge
    int0flag = 1;
    _pop_(SFRS);
}


void main (void) 
{
#ifdef  print_function
    Enable_P31_UART0_VCOM_115200_printf();
    printf ("\n P25 INT0 external interrupt initial!!");
#endif
  
/*INT0 ENABLE */
    MFP_P25_INT0;                      //setting INT0 pin P0.6 as Quasi mode
    P25_INPUT_MODE;                    //Set input mode
    P25_PULLUP_ENABLE;                 //set pull up resistor.
    INT0_FALLING_EDGE_TRIG;            //setting trig condition level or edge
    ENABLE_INT0_INTERRUPT;             //INT0_Enable;
    ENABLE_GLOBAL_INTERRUPT;           //Global interrupt enable
    while(!int0flag);

#ifdef  print_function
    _push_(SFRS);
    SFRS = 0;
    printf ("\n INT0 interrupt !!");
    _pop_(SFRS);
#endif

    while(1);
}



