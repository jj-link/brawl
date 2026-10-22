#include <types.h>
#pragma force_active on

struct FnCalTime {
    s32 sec;
    s32 min;
    s32 hour;
    s32 mday;
    s32 mon;
    s32 year;
    s32 wday;
    s32 yday;
    s32 msec;
    s32 usec;
};

extern "C" s64 OSCalendarTimeToTicks(FnCalTime*);

extern "C" s64 fn_801525B4(int unused, s32* a, s32* b) {
    FnCalTime t;
    s32 mon;
    s32 mday;
    t.sec = b[0];
    t.min = b[1];
    t.hour = b[2];
    mday = a[0];
    t.mday = mday;
    mon = a[1];
    t.mon = mon;
    t.year = a[2];
    t.wday = a[3];
    t.yday = a[4];
    t.msec = 0;
    t.usec = 0;
    if (t.year < 0x7D0 || mon < 0 || mon > 0xB || mday < 1 || mday > 0x1F) {
        return 0;
    }
    return OSCalendarTimeToTicks(&t);
}
