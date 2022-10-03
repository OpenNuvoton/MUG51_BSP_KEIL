/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2022 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: MUG51 Pin interrupt demo
//***********************************************************************************************************
#include "MUG51.h"

unsigned char PinIntFlag;
/* IMPORTANT !! This define for printf code only. Disable this define to reduce code size. */
/******************************************************************************
Pin interrupt subroutine.
******************************************************************************/
void PinInterrupt_ISR (void) interrupt 7
{
    _push_(SFRS);

    SFRS = 0;
    switch(PIF)
    {
      case (SET_BIT0): PinIntFlag = SET_BIT0; PIF&=CLR_BIT0; break;
      case (SET_BIT2): PinIntFlag = SET_BIT2; PIF&=CLR_BIT2; break;
      default: break;
    }

    _pop_(SFRS);
}
/******************************************************************************
The main C function.  Program execution starts
here after stack initialization.
******************************************************************************/
void main (void) 
{
  /* UART0 initial setting
  ** include uart.c in Library for UART initial setting
  **UART0 define P3.1 TXD multi function setting
  **/
  Enable_P31_UART0_VCOM_115200_printf();
  printf("\n PIT test start!");
//----------------------------------------------------
//  P1.3 set as highlevel trig pin interrupt function
//  otherwise, MCU into idle mode.
//----------------------------------------------------

    MFP_P17_GPIO;
    MFP_P25_GPIO;

    GPIO_SetMode(Port1,BIT7,GPIO_MODE_INPUT);
    GPIO_SetMode(Port2,BIT5,GPIO_MODE_INPUT);
    GPIO_Pull_Enable(Port1,BIT7,PULLUP);
    GPIO_Pull_Enable(Port2,BIT5,PULLDOWN);
    GPIO_EnableInt(PIT0,FALLING,EDGE,Port1,7);
    GPIO_EnableInt(PIT2,HIGH,LEVEL,Port2,5);

    ENABLE_GLOBAL_INTERRUPT;                // global enable bit
    while(1)
    {
      switch(PinIntFlag)
      {
        case (SET_BIT0): printf("\n PIT0 interrupt!"); PinIntFlag&=CLR_BIT0; break;
        case (SET_BIT2): printf("\n PIT2 interrupt!"); PinIntFlag&=CLR_BIT2;break;
        default: break;
      }
    }
}


