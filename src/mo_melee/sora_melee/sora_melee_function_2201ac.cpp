#include <types.h>
#pragma force_active on

extern "C" {
s32 randi__Fl(s32);

void fn_27_2201AC(void* p) {
    u32 b;
    u32 a;
    s32 c;
    u8* base = (u8*)p;
    u16 t = *(u16*)(base + 0x78);
    s32 d;

    if (t == 0x3030) {
        b = 0x50;
        a = 0xA0;
        c = 0;
        d = 0;
    } else if (t == 0x30E0) {
        b = 8;
        a = 0xC;
        c = 0;
        d = 0;
    } else {
        s32* t780 = (s32*)(base + 0x70);
        if (((s32*)(*(t780)))[0x48 / 4] == 1) {
            b = 5;
            a = 0x14;
            c = 0;
            d = 0;
        } else {
            b = 0xA;
            a = 0x1E;
            c = 0;
            d = 0;
        }
    }

    u32 da = ((randi__Fl(0x64)) < d) ? c : 0;
    s32 val = da + (randi__Fl(a + 1));
    val = b + val;

    s16* t348 = (s16*)(base + 0xD6);
    *t348 = 0;
    s16* t637 = (s16*)(base + 0xD4);
    *t637 = (s16)val;
}
}
