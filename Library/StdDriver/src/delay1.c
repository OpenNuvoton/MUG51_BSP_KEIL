/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2022 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include "MUG51.h"

/* ------------------------------------------------------------------------------*/
/* ---  Timer 0  ----------------------------------------------------------------*/
/* ------------------------------------------------------------------------------*/
void Timer0_Delay1ms(unsigned int u16CNT)
{
    unsigned char TLTMP, THTMP;

    TIMER0_FSYS_DIV12;                                     //T0M=0, Timer0 Clock = Fsys/12
    ENABLE_TIMER0_MODE1;                                   //Timer0 is 16-bit mode
    TLTMP = LOBYTE(TIMER_DIV12_VALUE_1ms_FOSC_7372800);
    THTMP = HIBYTE(TIMER_DIV12_VALUE_1ms_FOSC_7372800);
  
    while (u16CNT != 0)
    {
      TL0=TLTMP;
      TH0=THTMP;
      set_TCON_TR0;                                    //Start Timer0
      while (!TF0);                       //Check Timer0 Time-Out Flag
      clr_TCON_TF0;
      clr_TCON_TR0;                       //Stop Timer0
      u16CNT --;
    }
      TL0  = 0; 
      TH0 = 0;

}
/* ---  Timer 0  --------------------------------------------------------------     */
void Timer0_Delay10ms(unsigned int u16CNT)
{
    unsigned char TLTMP, THTMP;
	
    TIMER0_FSYS_DIV12;                                     /*T0M=0, Timer0 Clock = Fsys/12  */
    ENABLE_TIMER0_MODE1;                                   /*Timer0 is 16-bit mode */
    TLTMP = LOBYTE(TIMER_DIV12_VALUE_10ms_FOSC_7372800);
    THTMP = HIBYTE(TIMER_DIV12_VALUE_10ms_FOSC_7372800);

    while (u16CNT != 0)
    {
      TL0=TLTMP;
      TH0=THTMP;
      set_TCON_TR0;                                       /*Start Timer0 */
      while (!TF0);                                       /*Check Timer0 Time-Out Flag  */
      clr_TCON_TF0;
      clr_TCON_TR0;                                       /*Stop Timer0 */
      u16CNT --;
    }
      TL0  = 0; 
      TH0 = 0;
}
/* ---  Timer 0  --------------------------------------------------------------     */
void Timer0_Delay50ms(unsigned int u16CNT)
{
    unsigned char TLTMP, THTMP;

    TIMER0_FSYS_DIV12;                                     /*T0M=0, Timer0 Clock = Fsys/12  */
    ENABLE_TIMER0_MODE1;                                   /*Timer0 is 16-bit mode */
    TLTMP = LOBYTE(TIMER_DIV12_VALUE_50ms_FOSC_7372800);
    THTMP = HIBYTE(TIMER_DIV12_VALUE_50ms_FOSC_7372800);

    while (u16CNT != 0)
    {
      TL0=TLTMP;
      TH0=THTMP;
      set_TCON_TR0;                                       /*Start Timer0 */
      while (!TF0);                                       /*Check Timer0 Time-Out Flag  */
      clr_TCON_TF0;
      clr_TCON_TR0;                                       /*Stop Timer0 */
      u16CNT --;
    }
      TL0  = 0; 
      TH0 = 0;
}

/* ------------------------------------------------------------------------------*/
/* ---  Timer 1  ----------------------------------------------------------------*/
/* ------------------------------------------------------------------------------*/
void Timer1_Delay1ms(unsigned int u16CNT)
{
    unsigned char TLTMP, THTMP;

    TIMER1_FSYS_DIV12;                                     /*T1M=0, Timer1 Clock = Fsys/12  */
    ENABLE_TIMER1_MODE1;                                   /*Timer1 is 16-bit mode */
    TLTMP = LOBYTE(TIMER_DIV12_VALUE_1ms_FOSC_7372800);
    THTMP = HIBYTE(TIMER_DIV12_VALUE_1ms_FOSC_7372800);

    while (u16CNT != 0)
    {
      TL1=TLTMP;
      TH1=THTMP;
      set_TCON_TR1;                                       /*Start Timer0 */
      while (!TF1);                                       /*Check Timer0 Time-Out Flag  */
      clr_TCON_TF1;
      clr_TCON_TR1;                                       /*Stop Timer0 */
      u16CNT --;
    }
      TL1 = 0; 
      TH1 = 0;
}
/* ---  Timer 1  --------------------------------------------------------------     */
void Timer1_Delay10ms(unsigned int u16CNT)
{
    unsigned char TLTMP, THTMP;

    TIMER1_FSYS_DIV12;                                     /*T1M=0, Timer1 Clock = Fsys/12  */
    ENABLE_TIMER1_MODE1;                                   /*Timer1 is 16-bit mode */
    TLTMP = LOBYTE(TIMER_DIV12_VALUE_10ms_FOSC_7372800);
    THTMP = HIBYTE(TIMER_DIV12_VALUE_10ms_FOSC_7372800);

    while (u16CNT != 0)
    {
      TL1=TLTMP;
      TH1=THTMP;
      set_TCON_TR1;                                       /*Start Timer0 */
      while (!TF1);                                       /*Check Timer0 Time-Out Flag  */
      clr_TCON_TF1;
      clr_TCON_TR1;                                       /*Stop Timer0 */
      u16CNT --;
    }
      TL1 = 0; 
      TH1 = 0;
}
/* ---  Timer 1  --------------------------------------------------------------     */
void Timer1_Delay50ms(unsigned int u16CNT)
{
    unsigned char TLTMP, THTMP;

    TIMER1_FSYS_DIV12;                                     /*T1M=0, Timer1 Clock = Fsys/12  */
    ENABLE_TIMER1_MODE1;                                   /*Timer1 is 16-bit mode */
    TLTMP = LOBYTE(TIMER_DIV12_VALUE_50ms_FOSC_7372800);
    THTMP = HIBYTE(TIMER_DIV12_VALUE_50ms_FOSC_7372800);

    while (u16CNT != 0)
    {
      TL1=TLTMP;
      TH1=THTMP;
      set_TCON_TR1;                                       /*Start Timer0 */
      while (!TF1);                                       /*Check Timer0 Time-Out Flag  */
      clr_TCON_TF1;
      clr_TCON_TR1;                                       /*Stop Timer0 */
      u16CNT --;
    }
      TL1 = 0; 
      TH1 = 0;
}

/* ----------------------------------------------------------------- */
/* ---  Timer 2  --------------------------------------------------------------     */
/* ----------------------------------------------------------------- */
void Timer2_Delay1ms(unsigned int u16CNT)
{
    unsigned char TLTMP, THTMP;

    SFRS = 0;T2MOD&=0x8F;T2MOD|=0x50;                     /* Timer 2 DIV128  */
    TLTMP = LOBYTE(TIMER_DIV128_VALUE_1ms_FOSC_7372800);
    THTMP = HIBYTE(TIMER_DIV128_VALUE_1ms_FOSC_7372800);

    while (u16CNT != 0)
    {
        TL2 = TLTMP;
        TH2 = THTMP;
        set_T2CON_TR2;                                    /* Start Timer2 */
        while (!TF2);                                     /* Check Timer2 Time-Out Flag  */
        clr_T2CON_TF2;
        clr_T2CON_TR2;                                    /* Stop Timer2  */
        u16CNT --;
    }
}
/* ---  Timer 2  --------------------------------------------------------------     */
void Timer2_Delay10ms(unsigned int u16CNT)
{
    unsigned char TLTMP, THTMP;

    SFRS = 0;T2MOD&=0x8F;T2MOD|=0x50;                     /* Timer 2 DIV128  */
    TLTMP = LOBYTE(TIMER_DIV128_VALUE_10ms_FOSC_7372800);
    THTMP = HIBYTE(TIMER_DIV128_VALUE_10ms_FOSC_7372800);

    while (u16CNT != 0)
    {
        TL2 = TLTMP;
        TH2 = THTMP;
        set_T2CON_TR2;                                    /* Start Timer2 */
        while (!TF2);                                     /* Check Timer2 Time-Out Flag  */
        clr_T2CON_TF2;
        clr_T2CON_TR2;                                    /* Stop Timer2  */
        u16CNT --;
    }
}

/* ---  Timer 2  --------------------------------------------------------------     */
void Timer2_Delay100ms(unsigned int u16CNT)
{
    unsigned char TLTMP, THTMP;

    SFRS = 0;T2MOD&=0x8F;T2MOD|=0x50;                     /* Timer 2 DIV128  */
    TLTMP = LOBYTE(TIMER_DIV128_VALUE_100ms_FOSC_7372800);
    THTMP = HIBYTE(TIMER_DIV128_VALUE_100ms_FOSC_7372800);

    while (u16CNT != 0)
    {
        TL2 = TLTMP;
        TH2 = THTMP;
        set_T2CON_TR2;                                    /* Start Timer2 */
        while (!TF2);                                     /* Check Timer2 Time-Out Flag  */
        clr_T2CON_TF2;
        clr_T2CON_TR2;                                    /* Stop Timer2  */
        u16CNT --;
    }
}
/* ---  Timer 2  --------------------------------------------------------------     */
void Timer2_Delay200ms(unsigned int u16CNT)
{
    unsigned char TLTMP, THTMP;

    SFRS = 0;T2MOD&=0x8F;T2MOD|=0x50;                     /* Timer 2 DIV128  */
    TLTMP = LOBYTE(TIMER_DIV128_VALUE_200ms_FOSC_7372800);
    THTMP = HIBYTE(TIMER_DIV128_VALUE_200ms_FOSC_7372800);

    while (u16CNT != 0)
    {
        TL2 = TLTMP;
        TH2 = THTMP;
        set_T2CON_TR2;                                    /* Start Timer2 */
        while (!TF2);                                     /* Check Timer2 Time-Out Flag  */
        clr_T2CON_TF2;
        clr_T2CON_TR2;                                    /* Stop Timer2  */
        u16CNT --;
    }
}
/* ---  Timer 2  --------------------------------------------------------------     */
void Timer2_Delay1s(unsigned int u16CNT)
{
    unsigned char TLTMP, THTMP;

    SFRS = 0;T2MOD&=0x8F;T2MOD|=0x70;                 /* Timer 2 DIV512  */
    TLTMP = LOBYTE(TIMER_DIV512_VALUE_1s_FOSC_7372800);
    THTMP = HIBYTE(TIMER_DIV512_VALUE_1s_FOSC_7372800);

    while (u16CNT != 0)
    {
        TL2 = TLTMP;
        TH2 = THTMP;
        set_T2CON_TR2;                                    /* Start Timer2 */
        while (!TF2);                                     /* Check Timer2 Time-Out Flag  */
        clr_T2CON_TF2;
        clr_T2CON_TR2;                                    /* Stop Timer2  */
        u16CNT --;
    }
}

/* ----------------------------------------------------------------- */
/* ---  Timer 3  --------------------------------------------------------------     */
/* ----------------------------------------------------------------- */
void Timer3_Delay500us(unsigned int u16CNT)
{
    unsigned char TLTMP, THTMP;

    SFRS=0; T3CON = 0x02;                               /* Timer3 Clock = Fsys/4  */
    TLTMP = LOBYTE(TIMER_DIV4_VALUE_500us_FOSC_7372800);
    THTMP = HIBYTE(TIMER_DIV4_VALUE_500us_FOSC_7372800);

    while (u16CNT != 0)
    {
        RL3 = TLTMP;
        RH3 = THTMP;
        set_T3CON_TR3;                                  /* Start Timer3 */
        while (!(T3CON&SET_BIT4));                      /* Check Timer3 Time-Out Flag  */
        clr_T3CON_TF3;
        clr_T3CON_TR3;                                      /* Stop Timer3  */
        u16CNT --;
    }
}
/* ---  Timer 3  --------------------------------------------------------------     */
void Timer3_Delay1ms(unsigned int u16CNT)
{
    unsigned char TLTMP, THTMP;

    SFRS=0; T3CON = 0x07;                                       /* Timer3 Clock = Fsys/128  */
    TLTMP = LOBYTE(TIMER_DIV128_VALUE_1ms_FOSC_7372800);
    THTMP = HIBYTE(TIMER_DIV128_VALUE_1ms_FOSC_7372800);

    while (u16CNT != 0)
    {
        RL3 = TLTMP;
        RH3 = THTMP;
        set_T3CON_TR3;                                  /* Start Timer3 */
        while (!(T3CON&SET_BIT4));                      /* Check Timer3 Time-Out Flag  */
        clr_T3CON_TF3;
        clr_T3CON_TR3;                                  /* Stop Timer3  */
        u16CNT --;
    }
}
/* ---  Timer 3  --------------------------------------------------------------     */
void Timer3_Delay10ms(unsigned int u16CNT)
{
    unsigned char TLTMP, THTMP;

    SFRS=0; T3CON = 0x07;                                       /* Timer3 Clock = Fsys/128  */
    TLTMP = LOBYTE(TIMER_DIV128_VALUE_10ms_FOSC_7372800);
    THTMP = HIBYTE(TIMER_DIV128_VALUE_10ms_FOSC_7372800);

    while (u16CNT != 0)
    {
        RL3 = TLTMP;
        RH3 = THTMP;
        set_T3CON_TR3;                                  /* Start Timer3 */
        while (!(T3CON&SET_BIT4));                      /* Check Timer3 Time-Out Flag  */
        clr_T3CON_TF3;
        clr_T3CON_TR3;                                  /* Stop Timer3  */
        u16CNT --;
    }
}
