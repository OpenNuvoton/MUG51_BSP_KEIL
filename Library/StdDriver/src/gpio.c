/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* SPDX-License-Identifier: Apache-2.0                                                                     */
/* Copyright(c) 2022 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

#include "MUG51.h"

 /**
  * @brief GPIO Pull up or Pull down enable setting
  * @param[in] u8Port Decides the GPIO port number Port0 ~ Port5
  * @param[in] u8PinMask Decides  bit of the port (SET_BIT0~SET_BIT7 use "|" to define multi bit).
  * @param[in] u8PullMode Decides the GPIO Pull up or pull down (PullUp/PullDown)
  * @return  None
  * @note none
  * @exmaple :   GPIO_Pull_Enable(P1,BIT0|BIT5|BIT7,PullUp);
  */
void GPIO_Pull_Enable(unsigned char u8Port, unsigned char u8PinMask, unsigned char u8PullMode)
{
  SFRS=1;
  switch (u8PullMode)
  {
    case PULLUP:
        switch(u8Port)
        {
          case Port0:  P0UP |= u8PinMask;  break;
          case Port1:  P1UP |= u8PinMask;  break;
          case Port2:  P2UP |= u8PinMask;  break;
          case Port3:  P3UP |= u8PinMask;  break;
          case Port4:  P4UP |= u8PinMask;  break;
          case Port5:  P5UP |= u8PinMask;  break;
//          case Port6:  P6UP |= u8PinMask;  break;
        }
    break;
    case PULLDOWN:
        switch(u8Port)
        {
          case Port0:  P0DW |= u8PinMask;  break;
          case Port1:  P1DW |= u8PinMask;  break;
          case Port2:  P2DW |= u8PinMask;  break;
          case Port3:  P3DW |= u8PinMask;  break;
          case Port4:  P4DW |= u8PinMask;  break;
          case Port5:  P5DW |= u8PinMask;  break;
//          case Port6:  P6DW |= u8PinMask;  break;
        }
    break;
    }
}


 /**
  * @brief GPIO Pull up or Pull down disable 
  * @param[in] u8Port Decides the GPIO port number Port0 ~ Port5
  * @param[in] u8PinMask Decides  bit of the port (SET_BIT0~SET_BIT7 use "|" to define multi bit).
  * @param[in] u8PullMode Decides the GPIO Pull up or pull down (PullUp/PullDown)
  * @return  None
  * @note none
  * @exmaple :   GPIO_Pull_Enable(P1,BIT0|BIT5,PullUp);
  */
void GPIO_Pull_Disable(unsigned char u8Port, unsigned char u8PinMask, unsigned char u8PullMode)
{
  SFRS=1;
  switch (u8PullMode)
  {
    case PULLUP:
        switch(u8Port)
        {
          case Port0:  P0UP &= ~u8PinMask;  break;
          case Port1:  P1UP &= ~u8PinMask;  break;
          case Port2:  P2UP &= ~u8PinMask;  break;
          case Port3:  P3UP &= ~u8PinMask;  break;
          case Port4:  P4UP &= ~u8PinMask;  break;
          case Port5:  P5UP &= ~u8PinMask;  break;
//          case Port6:  P6UP &= ~u8PinMask;  break;
        }
    break;
    case PULLDOWN:
        switch(u8Port)
        {
          case Port0:  P0DW &= ~u8PinMask;  break;
          case Port1:  P1DW &= ~u8PinMask;  break;
          case Port2:  P2DW &= ~u8PinMask;  break;
          case Port3:  P3DW &= ~u8PinMask;  break;
          case Port4:  P4DW &= ~u8PinMask;  break;
          case Port5:  P5DW &= ~u8PinMask;  break;
//          case Port6:  P6DW &= ~u8PinMask;  break;
        }
    break;
    }
}


 /**
  * @brief GPIO mode setting
  * @param[in] u8Port Decides the GPIO port number Port0 ~ Port5
  * @param[in] u8PinMask Decides  bit of the port ( from SET_BIT0~SET_BIT7 use "|" to define multi bit)
  * @param[in] u8Mode Decides the GPIO mode GPIO_MODE_INPUT / GPIO_MODE_PUSHPULL / GPIO_MODE_QUASI / GPIO_MODE_OPENDRAI for mode to select.
  * @return  None
  * @note Confirm multi function pin is defined as GPIO first. call function_define_ML51.h to define.
  * @exmaple :   GPIO_SetMode(Port1,BIT0|BIT7,GPIO_MODE_QUASI);
  */
void GPIO_SetMode(unsigned char u8Port, unsigned char u8PinMask, unsigned char u8Mode)
{
    unsigned char u8PnM1, u8PnM2;

    SFRS = 1;
    switch(u8Port)
    {
        case Port0:  u8PnM1 = P0M1;  u8PnM2 = P0M2;  break;
        case Port1:  u8PnM1 = P1M1;  u8PnM2 = P1M2;  break;
        case Port2:  u8PnM1 = P2M1;  u8PnM2 = P2M2;  break;
        case Port3:  u8PnM1 = P3M1;  u8PnM2 = P3M2;  break;
        case Port4:  u8PnM1 = P4M1;  u8PnM2 = P4M2;  break;
        case Port5:  u8PnM1 = P5M1;  u8PnM2 = P5M2;  break;
//        case Port6:  u8PnM1 = P6M1;  u8PnM2 = P6M2;  break;
    }
    switch(u8Mode)
    {
        case GPIO_MODE_QUASI:
            u8PnM1 &= ~u8PinMask;
            u8PnM2 &= ~u8PinMask;
            break;
        case GPIO_MODE_PUSHPULL:
            u8PnM1 &= ~u8PinMask;
            u8PnM2 |= u8PinMask;
            break;
        case GPIO_MODE_INPUT:
            u8PnM1 |= u8PinMask; 
            u8PnM2 &= ~u8PinMask;
            break;
        case GPIO_MODE_OPENDRAIN:
            u8PnM1 |= u8PinMask;
            u8PnM2 |= u8PinMask;
            break;
    }
    switch(u8Port)
    {
        case Port0:  P0M1 = u8PnM1;  P0M2 = u8PnM2;  break;
        case Port1:  P1M1 = u8PnM1;  P1M2 = u8PnM2;  break;
        case Port2:  P2M1 = u8PnM1;  P2M2 = u8PnM2;  break;
        case Port3:  P3M1 = u8PnM1;  P3M2 = u8PnM2;  break;
        case Port4:  P4M1 = u8PnM1;  P4M2 = u8PnM2;  break;
        case Port5:  P5M1 = u8PnM1;  P5M2 = u8PnM2;  break;
//        case Port6:  P6M1 = u8PnM1;  P6M2 = u8PnM2;  break;
    }
}

 /**
  * @brief GPIO auto return setting
  * @param[in] u8Port Decides the GPIO port number P40/P30/P21/P20)
  * @param[in] u8RTtime delay timing clock minimum ( 0/1/2/3)
  * @return  None
  * @note None.
  * @exmaple :   GPIO_AutoReturnHigh(Port40,3);
  */
void GPIO_AutoReturnHigh(unsigned char u8Port, unsigned char u8RTtime)
{
	SFRS=3;
	switch (u8Port)
	{
		case Port40: PRTHCON0|=u8RTtime<<6; break;
		case Port30: PRTHCON0|=u8RTtime<<4; break;
		case Port21: PRTHCON0|=u8RTtime<<2; break;
		case Port20: PRTHCON0|=u8RTtime; break;
	}
}