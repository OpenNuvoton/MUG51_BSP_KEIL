/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2022 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include "MUG51.h"
//***********************************************************************************************************
//  File Function: MUG51 GPIO toggle demo code
//***********************************************************************************************************


void main (void)
{

P22_QUASI_MODE;
P00 = 1;P01 = 1;
MFP_P01_PINV;
SFRS=1;P0S|=0X03;
	while(1); 

}



