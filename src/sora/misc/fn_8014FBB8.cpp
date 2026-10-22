#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct OSCalendarTime {
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
} OSCalendarTime;

extern void* g_GameGlobal;
extern "C" void* memset(void* dst, int c, unsigned long n);
extern "C" long long OSCalendarTimeToTicks(OSCalendarTime* time);

extern "C" {
long long fn_8014FBB8(void) {
    OSCalendarTime sp8;
    u8* r31;
    int year;

    r31 = *(u8**)((u8*)g_GameGlobal + 0x34);
    memset(&sp8, 0, 0x28);
    year = (u16)(r31[0x20] + (r31[0x1F] << 8));
    sp8.year = year;
    sp8.mon = r31[0x21] - 1;
    sp8.mday = r31[0x22];
    if (year < 1 || sp8.mday < 1) {
        return 0;
    }
    return OSCalendarTimeToTicks(&sp8);
}
}
