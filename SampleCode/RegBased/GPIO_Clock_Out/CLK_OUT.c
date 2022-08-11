/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2022 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  File Function: MUG51 clock out demo
//***********************************************************************************************************
#include "MUG51.h"


void main(void)
{
/* Enable 3 pin of clock out multi function pin define */
    MFP_P32_CLKO;
    P32_PUSHPULL_MODE;

    MFP_P46_CLKO;
    P46_PUSHPULL_MODE;

    MFP_P56_CLKO;
    P56_PUSHPULL_MODE;

    set_CKCON_CLOEN;                                  //System Clock Output Enable
    CKDIV = 0x78;                                      //System clock divider 240 for scope check

    while(1);
	/* =================== */
}

