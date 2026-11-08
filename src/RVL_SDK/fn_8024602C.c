#include <revolution/types.h>
#pragma force_active on

extern void fn_80242908(void*);

void fn_8024602C(void* a, int b, void* c, void* d)
{
    u8* base = (u8*)a;
    u8* dst;
    u8* src5;
    u8* src16;
    int x;
    int val;
    int i;
    int j;

    x = b * 0x16;
    *(u16*)(base + 4) = 0;
    val = x + 4;
    *(u16*)(base + 2) = val;
    base[8] = 0x11;
    base[9] = 0xC;
    base[0xA] = (u8)((val & 0xFFFF) - 3);
    if ((unsigned)b > 0xB)
        b = 0xB;
    base[0xB] = (u8)b;

    dst = base + 0xC;
    src5 = (u8*)c;
    src16 = (u8*)d;

    for (i = 0; i < b; i++) {
        dst[0] = src5[5];
        dst[1] = src5[4];
        dst[2] = src5[3];
        dst[3] = src5[2];
        dst[4] = src5[1];
        dst[5] = src5[0];
        src5 += 6;
        for (j = 0; j < 16; j++)
            dst[6 + j] = src16[15 - j];
        src16 += 16;
        dst += 22;
    }

    fn_80242908(a);
}
