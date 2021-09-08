
#define  FSYS_HXT   0
#define  FSYS_LXT   1
#define  FSYS_HIRC  2
#define  FSYS_LIRC  3
#define  FSYS_ECLK  4
#define  FSYS_MIRC  5


void FsysSelect(unsigned char u8FsysMode);
void ClockEnable(unsigned char u8FsysMode);
void ClockDisable(unsigned char u8FsysMode);
void ClockSwitch(unsigned char u8FsysMode);
void SW_Reset(void);
void Interrupt_Global(u8EAStatus);


