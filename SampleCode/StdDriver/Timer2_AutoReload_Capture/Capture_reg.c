/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2022 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: MUG51 TIMER 2 Capture function demo
//***********************************************************************************************************

#include "MUG51.h"
/**
 * @brief       Timer2  interrupt subroutine
 */
void Capture_ISR(void) interrupt 12      // Vector @  0x63
{
  unsigned char captemph,captempl;

_push_(SFRS);

    SFRS = 1;
    if (CAPCON0&SET_BIT0)
    {
       captemph = C0H;
       captempl = C0L;
       clr_CAPCON0_CAPF0;
    }
    else if (CAPCON0&SET_BIT2)
    {
       captemph = C2H;
       captempl = C2L;
       clr_CAPCON0_CAPF2;
    }
    SFRS = 0;
//    printf ("\n capture high byte = %BD", captemph);
//    printf ("\n capture low byte = %BD", captempl);
    DISABLE_TIMER2_CAP0;

_pop_(SFRS);
}


void main (void) 
{

    Enable_UART0_VCOM_printf();
    printf ("\n ML51 series capture demo." );
/* Setting Multi function pin setting for GPIO toggle */ 
    MFP_P33_IC0;
    P33_INPUT_MODE;                          //Define P33 as IC0 input pin.
    ENABLE_P33_PULLUP;                       //Since check falling edge enalbe internal pull high function.
    TIMER2_Capture(IC0,IC_GPIO,CaptureRising,2);

    MFP_P11_IC2;
    P11_INPUT_MODE;                          //Define P11 as IC2 input pin.
    ENABLE_P11_PULLUP;                       //Since check falling edge enalbe internal pull high function.
    TIMER2_Capture(IC2,IC_GPIO,CaptureEither,7);;

    TIMER2_Capture_Interrupt(Enable);
    Global_Interrupt(Enable);
    while(1);
}



