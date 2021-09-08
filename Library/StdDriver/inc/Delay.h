
/* define timer base value Fsys = 8MHz  */
/* @note    Since 8M instruction and calculate speed limitaion. the timer counter value should be less than actullay. */
#define TIMER_DIV12_VALUE_1ms_FOSC_8M       65536-650     /* 667*12    /8000000 = 1 mS,   (Timer divider = 12            )  */
#define TIMER_DIV12_VALUE_10ms_FOSC_8M      65536-6650    /* 6667*12   /8000000 = 10 mS   (Timer divider = 12            )  */
#define TIMER_DIV12_VALUE_50ms_FOSC_8M      65536-33320   /* 33335*12  /8000000 = 40 ms   (Timer divider = 12            )  */
#define TIMER_DIV4_VALUE_200us_FOSC_8M      65536-400     /* 400*4     /8000000 = 200 us  (Timer divider = 4             )  */
#define TIMER_DIV4_VALUE_500us_FOSC_8M      65536-1000    /* 1000*4    /8000000 = 500 us  (Timer divider = 4             )  */
#define TIMER_DIV4_VALUE_1ms_FOSC_8M        65536-2000    /* 2000*4    /8000000 = 1 mS,   (Timer divider = 4             )  */
#define TIMER_DIV4_VALUE_10ms_FOSC_8M       65536-20000   /* 20000*4   /8000000 = 10 mS,  (Timer divider = 4             )  */
#define TIMER_DIV16_VALUE_10ms_FOSC_8M      65536-5000    /* 5000*16   /8000000 = 10 ms   (Timer  divider = 16           )  */
#define TIMER_DIV64_VALUE_30ms_FOSC_8M      65536-3750    /* 3750*64   /8000000 = 30 ms   (Timer divider = 64            )  */
#define TIMER_DIV128_VALUE_1ms_FOSC_8M      65536-60      /* 62*128    /8000000 = 1 ms    (Timer divider = 128           )  */
#define TIMER_DIV128_VALUE_10ms_FOSC_8M     65536-625     /* 625*128   /8000000 = 10 ms   (Timer divider = 128           )  */
#define TIMER_DIV128_VALUE_100ms_FOSC_8M    65536-6250    /* 6250*128  /8000000 = 100 ms  (Timer divider = 128           )  */
#define TIMER_DIV128_VALUE_200ms_FOSC_8M    65536-12500   /* 12500*128 /8000000 = 200 ms  (Timer divider = 128           )  */
#define TIMER_DIV256_VALUE_500ms_FOSC_8M    65536-15625   /* 15625*256 /8000000 = 500 ms  (Timer divider = 256           )  */
#define TIMER_DIV512_VALUE_100ms_FOSC_8M    65536-1562    /* 1562*512  /8000000 = 100ms.  (Timer Divider = 512           )  */
#define TIMER_DIV512_VALUE_1s_FOSC_8M       65536-15625   /* 15625*512 /8000000 = 1 s.    (Timer Divider = 512           )  */

void Timer0_Delay1ms(unsigned long u32CNT);
void Timer0_Delay10ms(unsigned long u32CNT);
void Timer0_Delay50ms(unsigned long u32CNT);

void Timer1_Delay1ms(unsigned long u32CNT);
void Timer1_Delay10ms(unsigned long u32CNT);
void Timer1_Delay50ms(unsigned long u32CNT);

void Timer2_Delay1ms(unsigned long u32CNT);
void Timer2_Delay10ms(unsigned long u32CNT);
void Timer2_Delay100ms(unsigned long u32CNT);
void Timer2_Delay200ms(unsigned long u32CNT);
void Timer2_Delay1s(unsigned long u32CNT);

void Timer3_Delay500us(unsigned long u32CNT);
void Timer3_Delay1ms(unsigned long u32CNT);
void Timer3_Delay10ms(unsigned long u32CNT);
void Timer3_Delay100ms(unsigned long u32CNT);
void Timer2_Delay200ms(unsigned long u32CNT);
