#pragma force_active on
typedef unsigned int u32;

extern void __DBExceptionDestination(void);
extern u32 __DBInterface;
extern int DBVerbose;

void DBInit(void) {
    __DBInterface = 0x80000040;
    *(u32 *)0x80000048 = (u32)__DBExceptionDestination + 0x80000000;
    DBVerbose = 1;
}
