#pragma force_active on
typedef unsigned char u8;
typedef long long s64;

struct OSCalendarTime {
    int sec;
    int min;
    int hour;
    int mday;
    int mon;
    int year;
    int wday;
    int yday;
    int msec;
    int usec;
};

extern "C" s64 OSCalendarTimeToTicks(OSCalendarTime* t);
extern "C" void* memset(void* dst, int c, unsigned long n);
extern u8* g_GameGlobal;

extern "C" s64 fn_8014FB0C(void) {
    OSCalendarTime t;
    u8* p;
    unsigned int hi;
    unsigned int lo;
    int year;

    p = *(u8**)(g_GameGlobal + 0x34);
    memset(&t, 0, 0x28);
    hi = p[0x1b];
    lo = p[0x1c];
    year = (unsigned short)(lo + (hi << 8));
    t.year = year;
    t.mon = p[0x1d] - 1;
    t.mday = p[0x1e];
    if (year < 1 || t.mday < 1) {
        return 0;
    }
    return OSCalendarTimeToTicks(&t);
}
