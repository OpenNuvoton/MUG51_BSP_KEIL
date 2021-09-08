/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2021 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//  Date   : Apr/29/2021 
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: MlL51 read UCID demo
//***********************************************************************************************************
#include "MUG51.h"

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
    MFP_P31_UART0_TXD;
    P31_PUSHPULL_MODE;
    UART_Open(8000000,UART0_Timer3,38400);
    ENABLE_UART0_PRINTF;
#endif
  
    UCID_Read();
#ifdef print_function    
    /*printf must in SFR page 0 */
    _push_(SFRS);
    SFRS = 0;  
    printf ("\n UCID = ");
    for(i=0;i<12;i++)
    { 
       printf (" 0x%bx",UCIDBuffer[i]);
    }
    _pop_(SFRS);    
 #endif 
  while(1);


}