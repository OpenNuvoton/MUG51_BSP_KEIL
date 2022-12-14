/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2022 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: MUG51 Interrupt demo code
//***********************************************************************************************************

#include "MUG51.h"

//-----------------------------------------------------------------------------------------------------------
void INT0_ISR (void) interrupt 0          // Vector @  0x03
{
    _push_(SFRS);
 
     clr_TCON_IE0;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void Timer0_ISR (void) interrupt 1        // Vector @  0x0B
{
    _push_(SFRS);
 
    clr_TCON_TF0;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void INT1_ISR (void) interrupt 2          // Vector @  0x13
{
    _push_(SFRS);
 
    clr_TCON_IE1;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void Timer1_ISR (void) interrupt 3        // Vector @  0x1B
{
    _push_(SFRS);
 
    clr_TCON_TF1;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void UART0_ISR (void) interrupt 4         // Vector @  0x23
{
    _push_(SFRS);
 
    clr_SCON_RI;
    clr_SCON_TI;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void Timer2_ISR (void) interrupt 5        // Vector @  0x2B
{
    _push_(SFRS);
 
    clr_T2CON_TF2;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void I2C0_ISR (void) interrupt 6           // Vector @  0x33
{
    _push_(SFRS);
 
    clr_I2C0TOC_I2TOF;
    clr_I2C0CON_SI;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void Pin_INT_ISR (void) interrupt 7           // Vector @  0x3B
{
    _push_(SFRS);
 
    PIF = 0;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void BOD_ISR (void) interrupt 8           // Vector @  0x43
{
    _push_(SFRS);
 
    clr_BODCON0_BOF;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void SPI0_ISR (void) interrupt 9           // Vector @  0x4B
{
    _push_(SFRS);
 
    clr_SPI0SR_SPIF;
    clr_SPI0SR_MODF;
    clr_SPI0SR_SPIOVF;
    SPI0SR &= 0x4F;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void WDT_ISR (void) interrupt 10          // Vector @  0x53
{
    _push_(SFRS);
 
    clr_WDCON_WDTF;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void Capture_ISR (void) interrupt 12      // Vector @  0x63
{
    _push_(SFRS);
 
    clr_CAPCON0_CAPF0;
    clr_CAPCON0_CAPF1;
    clr_CAPCON0_CAPF2;
    CAPCON0 &= 0xFC;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void PWM0_ISR (void) interrupt 13    // Vector @  0x6B
{
    _push_(SFRS);
 
    clr_PWM0CON0_PWMF;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void PWM0_Brake_ISR (void) interrupt 14    // Vector @  0x73
{
    _push_(SFRS);
 
    clr_PWM0FBD_FBF;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void UART1_ISR (void) interrupt 15          // Vector @  0x7B
{
    _push_(SFRS);
 
    clr_S1CON_RI_1;
    clr_S1CON_TI_1;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void Timer3_ISR (void) interrupt 16        // Vector @  0x83
{
    _push_(SFRS);
 
    clr_T3CON_TF3;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void WKT_ISR (void) interrupt 17            // Vector @  0x8B
{
    _push_(SFRS);
 
    clr_WKCON_WKTF;

    _pop_(SFRS);
}

//-----------------------------------------------------------------------------------------------------------
void HardFault_ISR (void) interrupt 18      // Vector @  0x93
{
    _push_(SFRS);
 
    clr_AUXR0_HFIF;

    _pop_(SFRS);
}

//-----------------------------------------------------------------------------------------------------------
void SMC0_ISR (void) interrupt 19          // Vector @  0x9B
{
    _push_(SFRS);
 
    clr_SC0IS_RDAIF;
    clr_SC0IS_TBEIF;
    clr_SC0IS_TERRIF;
    clr_SC0IS_BGTIF;
    clr_SC0IS_ACERRIF;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
void PDMA0_ISR (void) interrupt 20          // Vector @  0xA3
{
    _push_(SFRS);
 
  clr_DMA0TSR_HDONE;
  clr_DMA0TSR_FDONE;

    _pop_(SFRS);
}

//-----------------------------------------------------------------------------------------------------------
void PDMA1_ISR (void) interrupt 21          // Vector @  0xAB
{
    _push_(SFRS);
 
    clr_DMA1TSR_HDONE;
    clr_DMA1TSR_FDONE;

    _pop_(SFRS);
}

//-----------------------------------------------------------------------------------------------------------
void ACMP_ISR (void) interrupt 23          // Vector @  0xBB
{
    _push_(SFRS);
 
    clr_ACMPSR_ACMP0IF;
    clr_ACMPSR_ACMP1IF;
    ACMPSR &=0xFA;

    _pop_(SFRS);
}

//-----------------------------------------------------------------------------------------------------------
void I2C1_ISR (void) interrupt 24          // Vector @  0xC3
{
    _push_(SFRS);
 
    clr_I2C1TOC_I2TOF;
    clr_I2C1CON_SI;

    _pop_(SFRS);
}
//-----------------------------------------------------------------------------------------------------------
