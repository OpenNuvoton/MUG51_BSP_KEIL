/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2022 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include "MUG51.h"

/* ----------------------------------------------------------------- */
/* ---  Timer 0  --------------------------------------------------------------     */
/* ----------------------------------------------------------------- */
void Timer0_Delay1ms(unsigned long u32CNT)
{
    clr_CKCON_T0M;                                    /* T0M=0, Timer0 Clock = Fsys/12 */
    set_TMOD_M0_T0;                                   /* Timer0 is 16-bit mode */
    while (u32CNT != 0)
    {
        TL0 = LOBYTE(TIMER_DIV12_VALUE_1ms_FOSC_8000000);  /* Find  define in "delay.h"  */
        TH0 = HIBYTE(TIMER_DIV12_VALUE_1ms_FOSC_8000000);
        set_TCON_TR0;                                 /* Start Timer0 */
        while (TF0 != 1);                             /* Check Timer0 Time-Out Flag  */
        clr_TCON_TF0;
        u32CNT --;
    }
    clr_TCON_TR0;                                     /* Stop Timer0  */
}
/* ---  Timer 0  --------------------------------------------------------------     */
void Timer0_Delay10ms(unsigned long u32CNT)
{
    clr_CKCON_T0M;                                    /* T0M=0, Timer0 Clock = Fsys/12 */
    set_TMOD_M0_T0;                                   /* Timer0 is 16-bit mode */
    while (u32CNT != 0)
    {
        TL0 = LOBYTE(TIMER_DIV12_VALUE_10ms_FOSC_8000000);  /* Find  define in "delay.h"  */
        TH0 = HIBYTE(TIMER_DIV12_VALUE_10ms_FOSC_8000000);
        set_TCON_TR0;                                 /* Start Timer0 */
        while (TF0 != 1);                             /* Check Timer0 Time-Out Flag  */
        clr_TCON_TF0;
        u32CNT --;
    }
    clr_TCON_TR0;                                     /* Stop Timer0  */
}
/* ---  Timer 0  --------------------------------------------------------------     */
void Timer0_Delay50ms(unsigned long u32CNT)
{
    clr_CKCON_T0M;                                    /* T0M=0, Timer0 Clock = Fsys/12 */
    set_TMOD_M0_T0;                                   /* Timer0 is 16-bit mode */
    while (u32CNT != 0)
    {
        TL0 = LOBYTE(TIMER_DIV12_VALUE_50ms_FOSC_8000000);  /* Find  define in "delay.h"  */
        TH0 = HIBYTE(TIMER_DIV12_VALUE_50ms_FOSC_8000000);
        set_TCON_TR0;                                 /* Start Timer0 */
        while (TF0 != 1);                             /* Check Timer0 Time-Out Flag  */
        clr_TCON_TF0;
        u32CNT --;
    }
    clr_TCON_TR0;                                     /* Stop Timer0  */
}

/* ----------------------------------------------------------------- */
/* ---  Timer 1 --------------------------------------------------------------     */
/* ----------------------------------------------------------------- */
void Timer1_Delay1ms(unsigned long u32CNT)
{
    clr_CKCON_T1M;                                    /* T0M=1, Timer1 Clock = Fsys/12 */
    set_TMOD_M0_T1;                                   /* Timer1 is 16-bit mode */
    while (u32CNT != 0)
    {
        TL1 = LOBYTE(TIMER_DIV12_VALUE_1ms_FOSC_8000000);  /* Find  define in "delay.h"  */
        TH1 = HIBYTE(TIMER_DIV12_VALUE_1ms_FOSC_8000000);
        set_TCON_TR1;                                 /* Start Timer1 */
        while (TF1 != 1);                             /* Check Timer1 Time-Out Flag  */
        clr_TCON_TF1;
        u32CNT --;
    }
    clr_TCON_TR1;                                     /* Stop Timer1  */
}
/* ---  Timer 1  --------------------------------------------------------------     */
void Timer1_Delay10ms(unsigned long u32CNT)
{
    clr_CKCON_T1M;                                    /* T0M=1, Timer1 Clock = Fsys/12 */
    set_TMOD_M0_T1;                                   /* Timer1 is 16-bit mode */
    while (u32CNT != 0)
    {
        TL1 = LOBYTE(TIMER_DIV12_VALUE_10ms_FOSC_8000000); /* Find  define in "delay.h"  */
        TH1 = HIBYTE(TIMER_DIV12_VALUE_10ms_FOSC_8000000);
        set_TCON_TR1;                                 /* Start Timer1 */
        while (TF1 != 1);                             /* Check Timer1 Time-Out Flag  */
        clr_TCON_TF1;
        u32CNT --;
    }
    clr_TCON_TR1;                                     /* Stop Timer1  */
}
/* ---  Timer 1  --------------------------------------------------------------     */
void Timer1_Delay50ms(unsigned long u32CNT)
{
    clr_CKCON_T1M;                                    /* T0M=1, Timer1 Clock = Fsys/12 */
    set_TMOD_M0_T1;                                   /* Timer1 is 16-bit mode */
    while (u32CNT != 0)
    {
        TL1 = LOBYTE(TIMER_DIV12_VALUE_50ms_FOSC_8000000); /* Find  define in "delay.h"  */
        TH1 = HIBYTE(TIMER_DIV12_VALUE_50ms_FOSC_8000000);
        set_TCON_TR1;                                 /* Start Timer1 */
        while (TF1 != 1);                             /* Check Timer1 Time-Out Flag  */
        clr_TCON_TF1;
        u32CNT --;
    }
    clr_TCON_TR1;                                     /* Stop Timer1  */
}

/* ----------------------------------------------------------------- */
/* ---  Timer 2  --------------------------------------------------------------     */
/* ----------------------------------------------------------------- */
void Timer2_Delay1ms(unsigned long u32CNT)
{
    SFRS = 0;T2MOD&=0x8F;T2MOD|=0x50;                 /* Timer 2 DIV128  */
    while (u32CNT != 0)
    {
        TL2 = LOBYTE(TIMER_DIV128_VALUE_1ms_FOSC_8000000); /* Find  define in "delay.h"  */
        TH2 = HIBYTE(TIMER_DIV128_VALUE_1ms_FOSC_8000000);
        set_T2CON_TR2;                                /* Start Timer2 */
        while (TF2 != 1);                             /* Check Timer2 Time-Out Flag  */
        clr_T2CON_TF2;
        u32CNT --;
    }
    clr_T2CON_TR2;                                    /* Stop Timer2  */
}
/* ---  Timer 2  --------------------------------------------------------------     */
void Timer2_Delay10ms(unsigned long u32CNT)
{
    SFRS = 0;T2MOD&=0x8F;T2MOD|=0x50;                 /* Timer 2 DIV128  */
    while (u32CNT != 0)
    {
        TL2 = LOBYTE(TIMER_DIV128_VALUE_10ms_FOSC_8000000);/* Find  define in "delay.h"  */
        TH2 = HIBYTE(TIMER_DIV128_VALUE_10ms_FOSC_8000000);
        set_T2CON_TR2;                                /* Start Timer2 */
        while (TF2 != 1);                             /* Check Timer2 Time-Out Flag  */
        clr_T2CON_TF2;
        u32CNT --;
    }
    clr_T2CON_TR2;                                    /* Stop Timer2  */
}
/* ---  Timer 2  --------------------------------------------------------------     */
void Timer2_Delay100ms(unsigned long u32CNT)
{
    SFRS = 0;T2MOD&=0x8F;T2MOD|=0x50;                 /* Timer 2 DIV128  */
    while (u32CNT != 0)
    {
        TL2 = LOBYTE(TIMER_DIV128_VALUE_100ms_FOSC_8000000);/* Find  define in "delay.h"  */
        TH2 = HIBYTE(TIMER_DIV128_VALUE_100ms_FOSC_8000000);
        set_T2CON_TR2;                                /* Start Timer2 */
        while (TF2 != 1);                             /* Check Timer2 Time-Out Flag  */
        clr_T2CON_TF2;
        u32CNT --;
    }
    clr_T2CON_TR2;                                    /* Stop Timer2  */
}
/* ---  Timer 2  --------------------------------------------------------------     */
void Timer2_Delay200ms(unsigned long u32CNT)
{
    SFRS = 0;T2MOD&=0x8F;T2MOD|=0x50;                 /* Timer 2 DIV128  */
    while (u32CNT != 0)
    {
        TL2 = LOBYTE(TIMER_DIV128_VALUE_200ms_FOSC_8000000);/* Find  define in "delay.h"  */
        TH2 = HIBYTE(TIMER_DIV128_VALUE_200ms_FOSC_8000000);
        set_T2CON_TR2;                                /* Start Timer2 */
        while (TF2 != 1);                             /* Check Timer2 Time-Out Flag  */
        clr_T2CON_TF2;
        u32CNT --;
    }
    clr_T2CON_TR2;                                    /* Stop Timer2  */
}
/* ---  Timer 2  --------------------------------------------------------------     */
void Timer2_Delay1s(unsigned long u32CNT)
{
    SFRS = 0;T2MOD&=0x8F;T2MOD|=0x70;                 /* Timer 2 DIV512  */
    while (u32CNT != 0)
    {
        TL2 = LOBYTE(TIMER_DIV512_VALUE_1s_FOSC_8000000);  /* Find  define in "delay.h"  */
        TH2 = HIBYTE(TIMER_DIV512_VALUE_1s_FOSC_8000000);
        set_T2CON_TR2;                                /* Start Timer2 */
        while (TF2 != 1);                             /* Check Timer2 Time-Out Flag  */
        clr_T2CON_TF2;
        u32CNT --;
    }
    clr_T2CON_TR2;                                    /* Stop Timer2  */
}

/* ----------------------------------------------------------------- */
/* ---  Timer 3  --------------------------------------------------------------     */
/* ----------------------------------------------------------------- */
void Timer3_Delay500us(unsigned long u32CNT)
{
    SFRS=0; T3CON = 0x02;                               /* Timer3 Clock = Fsys/4  */
    while (u32CNT != 0)
    {
        RL3 = LOBYTE(TIMER_DIV4_VALUE_500us_FOSC_8000000);   /* Find  define in "delay.h"  */
        RH3 = HIBYTE(TIMER_DIV4_VALUE_500us_FOSC_8000000);
        set_T3CON_TR3;                                  /* Start Timer3 */
        while (!(T3CON&SET_BIT4));                      /* Check Timer3 Time-Out Flag  */
        clr_T3CON_TF3;
        u32CNT --;
    }
    clr_T3CON_TR3;                                      /* Stop Timer3  */
}
/* ---  Timer 3  --------------------------------------------------------------     */
void Timer3_Delay1ms(unsigned long u32CNT)
{
    T3CON = 0x07;                                       /* Timer3 Clock = Fsys/128  */
    while (u32CNT != 0)
    {
        RL3 = LOBYTE(TIMER_DIV128_VALUE_1ms_FOSC_8000000);   /* Find  define in "delay.h"  */
        RH3 = HIBYTE(TIMER_DIV128_VALUE_1ms_FOSC_8000000);
        set_T3CON_TR3;                                  /* Start Timer3 */
        while (!(T3CON&SET_BIT4));                      /* Check Timer3 Time-Out Flag  */
        clr_T3CON_TF3;
        u32CNT --;
    }
    clr_T3CON_TR3;                                     /* Stop Timer3  */
}
/* ---  Timer 3  --------------------------------------------------------------     */
void Timer3_Delay10ms(unsigned long u32CNT)
{
    T3CON = 0x07;                               //Timer3 Clock = Fsys/128
    while (u32CNT != 0)
    {
        RL3 = LOBYTE(TIMER_DIV128_VALUE_10ms_FOSC_8000000);   /* Find  define in "delay.h"  */
        RH3 = HIBYTE(TIMER_DIV128_VALUE_10ms_FOSC_8000000);
        set_T3CON_TR3;                                  /* Start Timer3 */
        while (!(T3CON&SET_BIT4));                      /* Check Timer3 Time-Out Flag  */
        clr_T3CON_TF3;
        u32CNT --;
    }
    clr_T3CON_TR3;                                     /* Stop Timer3  */
}
