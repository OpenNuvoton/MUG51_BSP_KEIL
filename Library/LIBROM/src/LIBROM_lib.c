#include "MUG51.h"

void LIBROM_PD_RETURN(void)
{
_push_(SFRS);
    SFRS=0;
    while(!(AUXR0&SET_BIT2))
      set_PCON_PD;
_pop_(SFRS);
}

void LIBROM_LOOP_RETURN(void)
{
_push_(SFRS);
    SFRS=0;
    while(!(AUXR0&SET_BIT2));
_pop_(SFRS);
}

void LIBROM_DELAY_10US(void)
{
  unsigned char data i;
       for (i=0;i<0x2;i++)
       {
          _nop_();
          _nop_();
          _nop_();
          _nop_();
          _nop_();
          _nop_();
          _nop_();
          _nop_();
       }
}

void LIBROM_DELAY_50US(void)
{
  unsigned char data i;
       for (i=0;i<18;i++)
       {
          _nop_();
       }
}


void LIBROM_DELAY_100US(void)
{
  unsigned char data i,j;
    for (j=0;j<3;j++) 
    {
       for (i=0;i<10;i++)
       {
          _nop_();
       }
      _nop_();
    }
    for (i=0;i<1;i++);
}

void LIBROM_DELAY_1MS(void)
{
  unsigned char data i,j;
    for (j=0;j<0x2;j++) 
    {
       for (i=0;i<0xBC;i++)
       {
          _nop_();
       }
    } 
}

void LIBROM_DELAY_10MS(void)
{
  unsigned char data i,j;
    for (j=0;j<0x10;j++) 
    {
       for (i=0;i<0xEC;i++)
       {
          _nop_();
       }
        _nop_();
        _nop_();
    } 
}

void LIBROM_DELAY_100MS(void)
{
  unsigned char data i,j;

    for (j=0;j<0x8F;j++) 
    {
       for (i=0;i<0xFC;i++)
       {
          _nop_(); 
          _nop_();
       }
    }
    for (i=0;i<0x5e;i++)
    {
          _nop_();
     }

}



