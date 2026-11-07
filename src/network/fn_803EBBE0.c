#include <revolution/OS/OSTime.h>
#pragma force_active on

extern void fn_801E1D80(s64, OSCalendarTime*);

void fn_803EBBE0(int* date, int* time) {
    OSCalendarTime cal;
    fn_801E1D80(OSGetTime(), &cal);
    date[0] = cal.year;
    date[1] = cal.month + 1;
    date[2] = cal.mday;
    time[0] = cal.hour;
    time[1] = cal.min;
    time[2] = cal.sec;
}
