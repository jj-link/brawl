#include <types.h>
#include <string.h>
#include <revolution/OS/OSTime.h>
#include <revolution/OS/OSCache.h>
#include <gm/gm_global.h>
#pragma force_active on

static inline int decimal(const char* p) {
    char a = p[0];
    char b = p[1];
    return (a - '0') * 10 + (b - '0');
}

static inline void copyText(u16* dst, const u16* src, int n) {
    int i = 0;
    while (*src != 0 && i < n) {
        *dst = *src;
        ++src;
        ++dst;
        ++i;
    }
    *dst = 0;
}

extern "C" {
    u32 getLanguage__10GameGlobalFv(GameGlobal* self);
    void fn_802608BC(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);

    void fn_11_7E7C(void* arg0, void* arg1, s32 arg2, s32 arg3, void* arg4) {
        char* str = *(char**)((char*)arg0 + arg2 * 0x10 + 0x54) + arg3 * 0x18;
        int f8 = *(unsigned char*)((char*)arg1 + 8);

        int flag;
        if (f8 == 3) {
            flag = 2;
        } else if (str[5] == 0x30 && str[6] == 0x30) {
            flag = 1;
        } else {
            flag = 0;
        }

        OSCalendarTime cal;
        char buf[0x1C00];

        switch (flag) {
            case 2:
                memset(&cal, 0, sizeof(cal));
                getLanguage__10GameGlobalFv(g_GameGlobal);
                cal.year = 0x7d8;
                cal.month = 0;
                cal.mday = 1;
                cal.hour = 0;
                cal.min = 0;
                {
                    u64 ticks = OSCalendarTimeToTicks(&cal);
                    *(s32*)((char*)arg4 + 0x4C) = (s32)ticks;
                    *(s32*)((char*)arg4 + 0x48) = (s32)(ticks >> 32);
                }
                break;
            case 1:
                *(u64*)((char*)arg4 + 0x48) = *(u64*)arg1;
                break;
            case 0:
            default:
                memset(&cal, 0, sizeof(cal));
                cal.year = decimal(str + 3);
                cal.year += 2000;
                cal.month = decimal(str + 5);
                cal.month -= 1;
                cal.mday = decimal(str + 7);
                cal.hour = decimal(str + 0xA);
                cal.min = decimal(str + 0xC);
                {
                    u64 ticks = OSCalendarTimeToTicks(&cal);
                    *(s32*)((char*)arg4 + 0x4C) = (s32)ticks;
                    *(s32*)((char*)arg4 + 0x48) = (s32)(ticks >> 32);
                }
                break;
        }

        if (f8 == 1) {
            copyText((u16*)((char*)arg4 + 0x14), (u16*)((char*)arg1 + 0x1E), 5);
        } else {
            *(u16*)((char*)arg4 + 0x14) = 0;
        }

        {
            copyText((u16*)((char*)arg4 + 0x20), (u16*)((char*)arg1 + 0x54), 0x10);
        }

        fn_802608BC(buf, *(s32*)((char*)arg1 + 0x80), *(s32*)((char*)arg1 + 0x7C),
                    *(s32*)((char*)arg4 + 0x10), 0x12C00, 6, 1, 0);

        DCFlushRange((void*)*(s32*)((char*)arg4 + 0x10), 0x12C00);

        u8 b = *(u8*)((char*)arg1 + 0x78);
        *(s32*)((char*)arg4 + 0x50) = f8;
        *(u8*)((char*)arg4 + 0xC) = (b != 0);
    }
}
