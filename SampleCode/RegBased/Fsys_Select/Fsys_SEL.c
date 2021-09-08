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
//  File Function: MUG51 System clock modify demo
//***********************************************************************************************************
#include "MUG51.h"


//========================================================================
//  The test process:
//  1. Power on is run as default HIRC,
//  2. if P4.6 toggle to GND system clock run in LIRC.
//  3. if P4.6 toggle to GND Again system clock run in HXT.
//  PLEASE CONFIRM THE EXTERNAL XTAL IS CONNECT
//========================================================================
void main(void)
{

/* Note
  MCU power on system clock is HIRC (24 MHz)
*/
    MFP_P46_GPIO;
    P46_INPUT_MODE;
    ENABLE_P46_PULLUP;
  
    MFP_P03_CLKO;
    P03_QUASI_MODE;
    set_CKCON_CLOEN;

    while (P46);
    FsysSelect(FSYS_LIRC);
    while (P46);
    FsysSelect(FSYS_MIRC);;
    while(1);

}

