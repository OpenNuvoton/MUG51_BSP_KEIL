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
#include "librom.h"

unsigned char ct;
void WakeUp_Timer_ISR (void)   interrupt 17
{
_push_(SFRS);

    if(ct==10)
    {
        SET_EXIT_LIBROM_FLAG;
    }
    ct++;
    clr_WKCON_WKTF;                     //clear interrupt flag
    set_WKCON_WKTR;

_pop_(SFRS);
}

  void WKTInit(void)
{
    SFRS = 0;
    WKCON = 0x00;                     //timer base 10k, Pre-scale = 1/16
    SFRS = 2;
    RWKH = 0xFC;
    SFRS = 0;
    RWKL = 0;                         //  if prescale is 0x00, never set RWK = 0xff
    ENABLE_WKT_INTERRUPT;             // enable WKT interrupt
    ENABLE_GLOBAL_INTERRUPT;
    set_WKCON_WKTR;
}

void main(void)
{

  DISABLE_BOD;
  ALL_GPIO_QUASI_MODE;
  WKTInit();
  EA =1;
  LIBROM_PD_RETURN();
  while(1)
  {
    P22^=1;
    LIBROM_DELAY_10US();
    P22^=1;
    LIBROM_DELAY_50US();
    P22^=1;
    LIBROM_DELAY_100US();
    P22^=1;
    LIBROM_DELAY_1MS();
    P22^=1;
    LIBROM_DELAY_10MS();

    if(ct==20)
    { 
    ct=0; 
    CLR_EXIT_LIBROM_FLAG;
    LIBROM_PD_RETURN();
    }
  }
  while(1);
}

