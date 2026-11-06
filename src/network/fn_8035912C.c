#include <revolution/OS/OSTime.h>

#pragma force_active on

typedef struct Arr5 {
    s32 a0;
    s32 a4;
    s32 a8;
    s32 aC;
    s32 a10;
} Arr5;

typedef struct SbsState {
    s32 state;
    s32 status;
    s32 pad08[2];
    s32 hi10;
    s32 lo14;
    s32 pad18[8];
    s32 f38;
    Arr5 *p3C;
    Arr5 *p40;
    s32 f44;
    s32 pad48;
    u32 count4C;
    s32 *p50;
} SbsState;

extern SbsState lbl_8048E680;
extern char lbl_80415790[];
extern void fn_80335638(int, const char *, ...);
extern void *fn_80355454(s32 *);

static u32 bswap32(u32 x) {
    return ((x >> 24) | ((x >> 8) & 0xFF00)) | ((x << 24) | ((x << 8) & 0xFF0000));
}

#define SW(i) ((s32)bswap32(p[i]))

void fn_8035912C(void) {
    OSCalendarTime t;
    u32 *p;
    u32 *q;
    s32 sp8;
    s32 code;
    s32 sub;
    s32 off;
    u32 v;
    u32 i;
    s64 ticks;
    s64 now;
    s64 diff;

    sp8 = 0;
    p = (u32 *)fn_80355454(&sp8);
    code = SW(1);
    sub = SW(0);
    switch (code) {
    case -1:
        fn_80335638(8, lbl_80415790 + 0x17D);
        lbl_8048E680.state = 0;
        lbl_8048E680.status = 5;
        break;
    case -2:
        fn_80335638(8, lbl_80415790 + 0x1A9);
        lbl_8048E680.state = 0;
        lbl_8048E680.status = 6;
        break;
    case -3:
        fn_80335638(8, lbl_80415790 + 0x1D9);
        lbl_8048E680.state = 0;
        lbl_8048E680.status = 7;
        break;
    case -4:
        fn_80335638(8, lbl_80415790 + 0x20B);
        lbl_8048E680.state = 0;
        lbl_8048E680.status = 8;
        break;
    case -100:
        fn_80335638(8, lbl_80415790 + 0x23C);
        lbl_8048E680.state = 0;
        lbl_8048E680.status = 5;
        break;
    case -200:
        fn_80335638(8, lbl_80415790 + 0x26A);
        lbl_8048E680.state = 0;
        lbl_8048E680.status = 9;
        break;
    case -201:
        fn_80335638(8, lbl_80415790 + 0x298);
        lbl_8048E680.state = 0;
        lbl_8048E680.status = 0xA;
        break;
    case -300:
        fn_80335638(8, lbl_80415790 + 0x2C1);
        lbl_8048E680.state = 0;
        lbl_8048E680.status = 0xC;
        break;
    case -301:
        fn_80335638(8, lbl_80415790 + 0x2EF);
        lbl_8048E680.state = 0;
        lbl_8048E680.status = 0xC;
        break;
    default:
        fn_80335638(8, lbl_80415790 + 0x325);
        lbl_8048E680.state = 0;
        lbl_8048E680.status = 0xB;
        break;
    case 0:
        switch (sub) {
        case 0:
            lbl_8048E680.state = 6;
            break;
        case 1:
            lbl_8048E680.state = 0;
            lbl_8048E680.status = 0;
            break;
        case 2:
            lbl_8048E680.p3C->aC = 0;
            lbl_8048E680.p3C->a10 = 0;
            lbl_8048E680.p40->aC = 0;
            lbl_8048E680.p40->a10 = 0;
            t.wday = 0;
            t.yday = 0;
            t.msec = 0;
            t.usec = 0;
            lbl_8048E680.f44 = SW(2);
            lbl_8048E680.f38 = SW(3);
            lbl_8048E680.p3C->a8 = SW(4);
            lbl_8048E680.p3C->a4 = SW(5);
            lbl_8048E680.p3C->a0 = SW(6);
            lbl_8048E680.p40->a8 = SW(7);
            lbl_8048E680.p40->a4 = SW(8);
            lbl_8048E680.p40->a0 = SW(9);
            t.year = SW(10);
            t.month = SW(11);
            t.mday = SW(12);
            t.hour = SW(13);
            t.min = SW(14);
            t.sec = SW(15);
            ticks = OSCalendarTimeToTicks(&t);
            now = OSGetTime();
            diff = now - ticks;
            lbl_8048E680.lo14 = (s32)diff;
            lbl_8048E680.hi10 = (s32)(diff >> 32);
            lbl_8048E680.state = 9;
            break;
        case 3:
            q = p;
            for (i = 0, off = 0; i < lbl_8048E680.count4C; off += 4) {
                v = q[2];
                q++;
                i++;
                *(u32 *)((char *)lbl_8048E680.p50 + off) = bswap32(v);
            }
            lbl_8048E680.state = 0;
            lbl_8048E680.status = 0;
            break;
        default:
            fn_80335638(8, lbl_80415790 + 0x352);
            break;
        }
        break;
    }
}
