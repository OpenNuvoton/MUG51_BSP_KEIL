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
#include "MUG51.h"

//***********************************************************************************************************
//  LIBROM Entry CODE
//***********************************************************************************************************
void LIBROM_PD_RETURN(void)
{
#pragma ASM 
    LJMP   0x4000
    RET
#pragma ENDASM
}

void LIBROM_LOOP_RETURN(void)
{
#pragma ASM
    LJMP   4020H
    RET
#pragma ENDASM
}

void LIBROM_DELAY_10US(void)
{
#pragma ASM 
    LJMP   4040H
    RET
#pragma ENDASM
}

void LIBROM_DELAY_50US(void)
{
#pragma ASM 
    LJMP   4060H
    RET
#pragma ENDASM
}

void LIBROM_DELAY_100US(void)
{
#pragma ASM 
    LJMP   40A0H
    RET
#pragma ENDASM
}
void LIBROM_DELAY_1MS(void)
{
#pragma ASM 
    LJMP   40E0H
    RET
#pragma ENDASM
}

void LIBROM_DELAY_10MS(void)
{
#pragma ASM 
    LJMP   4120H
    RET
#pragma ENDASM
}

void LIBROM_DELAY_100MS(void)
{
#pragma ASM 
    LJMP   4160H
    RET
#pragma ENDASM
}

