#pragma force_active on

typedef unsigned char u8;
typedef signed int s32;
typedef signed long long s64;

extern "C" void* memset(void* dst, int c, unsigned long n);

struct OSCalendarTime {
    s32 sec;
    s32 min;
    s32 hour;
    s32 mday;
    s32 month;
    s32 year;
    s32 wday;
    s32 yday;
    s32 msec;
    s32 usec;
};

extern "C" s64 OSCalendarTimeToTicks(const OSCalendarTime* cal);

class GameGlobal {
public:
    u8 _pad[0x34];
    u8* m_nteData;
};

extern "C" GameGlobal* g_GameGlobal;

extern "C" s64 fn_8014F710(void) {
    OSCalendarTime cal;
    u8* nte = g_GameGlobal->m_nteData;
    memset(&cal, 0, 0x28);
    cal.year = (nte[4] + (nte[3] << 8)) & 0xFFFF;
    cal.month = nte[5] - 1;
    cal.mday = nte[6];
    if (cal.year < 1 || cal.mday < 1) {
        return 0;
    }
    return OSCalendarTimeToTicks(&cal);
}
