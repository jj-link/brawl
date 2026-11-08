#pragma force_active on
#include <revolution/OS/OSTime.h>

extern "C" void OSCreateAlarm(void*);
extern "C" void OSSetPeriodicAlarm(void*, unsigned long long,
                                  unsigned long long, void (*)(void*, void*));
extern "C" void fn_801C2D8C(void*, void*);

extern "C" void fn_801C2CAC(unsigned char* arg0)
{
    if (arg0[0] == 0) {
        unsigned int period;
        unsigned int product;
        unsigned int quotient;
        unsigned long long time;

        OSCreateAlarm(arg0 + 8);
        time = (unsigned long long)OSGetTime();
        quotient = OS_USEC_TO_TICKS(8);
        product = quotient * 0x65B9ABu;
        period = product / 8000u;
        OSSetPeriodicAlarm(arg0 + 8, time, (unsigned long long)period,
                           fn_801C2D8C);
        arg0[0] = 1;
    }
}
