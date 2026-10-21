#include <stdarg.h>
#pragma force_active on

extern void fn_801E28F8(void);
extern void fn_801D7184(int);
extern void fn_801D716C(int);
extern int *fn_801D718C(int, int);
extern void fn_801D9F2C(unsigned long long, int, int *, int);
extern void fn_801DF700(void);

void fn_801DA3D4(int arg0, int arg1, ...)
{
    va_list args;
    int *buffer;
    int i;

    fn_801E28F8();
    fn_801D7184(0x81280000);
    fn_801D716C(0x812F0000);
    buffer = fn_801D718C(4, 0x1000);

    va_start(args, arg1);
    i = 0;
    while ((buffer[i++] = arg1) != 0) {
        arg1 = va_arg(args, int);
    }
    va_end(args);

    fn_801D9F2C(0x100000002ULL, arg0, buffer, 0);
    fn_801DF700();
}
