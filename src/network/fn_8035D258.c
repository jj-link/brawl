#include <stddef.h>
#pragma force_active on

extern long long OSGetTime(void);
extern long long fn_803F1470(long long, long long);

void fn_8035D258(void *arg0) {
    long long time = OSGetTime();
    long long divisor = (unsigned int)* (unsigned int *)0x800000F8 >> 2;
    long long result = fn_803F1470(time, divisor);
    if (arg0 != NULL)
        *(long long *)arg0 = result;
}
