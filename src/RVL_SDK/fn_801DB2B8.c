#include <stdarg.h>
#include <revolution/OS/OSThread.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on
extern void fn_801E2FEC(void);
extern void fn_801E28F8(void);
extern void fn_801E0760(void);
extern void fn_801DF11C(int);
extern void fn_801D7184(int);
extern void fn_801D716C(int);
extern int *fn_801D718C(int, int);
extern void fn_801DAF04(unsigned long long, int, int *);
void fn_801DB2B8(unsigned long long arg0, int arg1, int arg2, ...)
{
    va_list args;
    int *buffer;
    int i;
    fn_801E2FEC();
    fn_801E28F8();
    fn_801E0760();
    fn_801DF11C(6);
    OSEnableScheduler();
    OSDisableInterrupts();
    fn_801D7184(0x81280000);
    fn_801D716C(0x812F0000);
    buffer = fn_801D718C(4, 0x1000);
    va_start(args, arg2);
    i = 0;
    while ((buffer[i++] = arg2) != 0) {
        arg2 = va_arg(args, int);
    }
    va_end(args);
    fn_801DAF04(arg0, arg1, buffer);
}