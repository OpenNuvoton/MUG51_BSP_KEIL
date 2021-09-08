/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2021 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: MUG51 simple GPIO toggle out demo code
//***********************************************************************************************************

#include "MUG51.h"


void main (void) 
{
    unsigned char ct;
    ALL_GPIO_QUASI_MODE;

    Enable_UART0_VCOM_38400_printf();

    for (ct=0;ct<5;ct++)
    {
      P0 = ~P0;
      P1 = ~P1;
      P2 = ~P2;
      P3 = ~P3;
      P4 = ~P4;
      P5 = ~P5;
      Timer0_Delay50ms(4);
    }
    P31 = 1;
    printf("\n Hello world!");
    while(1);
}


