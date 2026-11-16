#include <types.h>
#pragma force_active on

#define FLD(T, p, off) (*(T*)((u8*)(p) + (off)))

struct FlagsIn { u8 a : 2; u8 bit : 1; u8 rest : 5; };
struct FlagsOut { u8 bit : 1; u8 rest : 7; };

extern "C" void* memset(void*, int, unsigned long);
extern "C" s32 randi__Fl(s32);

extern "C" void fn_27_24AC3C(u8* arg0) {
    s32 off;
    s32 r27;
    s32 m;
    s32 r26;
    s32 r;
    s32 q;
    s32 k;
    u8 b;
    u16 h;

    FLD(u8, FLD(void*, arg0, 0xCC), 0x0) = (u8)((FLD(u8, FLD(void*, arg0, 0x44), 0x8) >> 2) & 0x3F);
    FLD(u8, FLD(void*, arg0, 0xCC), 0x1) = (u8)((FLD(u8, FLD(void*, arg0, 0x44), 0x9) >> 5) & 7);
    FLD(u8, FLD(void*, arg0, 0xCC), 0x2) = FLD(u8, FLD(void*, arg0, 0x44), 0x13);
    FLD(u8, FLD(void*, arg0, 0xCC), 0x3) = FLD(u8, FLD(void*, arg0, 0x44), 0x17);
    FLD(s32, FLD(void*, arg0, 0xCC), 0x4) = (s32)(FLD(u32, FLD(void*, arg0, 0x44), 0x20) / 3600);
    FLD(s32, FLD(void*, arg0, 0xCC), 0x1374) = (s32)((FLD(u8, FLD(void*, arg0, 0x44), 0xE) >> 5) & 7);
    ((FlagsOut*)((u8*)FLD(void*, arg0, 0xCC) + 0xE))->bit = ((FlagsIn*)((u8*)FLD(void*, arg0, 0x44) + 0x62))->bit;
    h = FLD(u16, FLD(void*, arg0, 0x44), 0x1A);
    FLD(u16, FLD(void*, arg0, 0xCC), 0xC) = h;
    FLD(u8, FLD(void*, arg0, 0xCC), 0x1378) = 9;
    r27 = FLD(s32, FLD(void*, arg0, 0xCC), 0x25C);
    r26 = FLD(s32, FLD(void*, arg0, 0xCC), 0x260);
    memset((u8*)FLD(void*, arg0, 0xCC) + 0x24, 0, 0x12B4);
    memset((u8*)FLD(void*, arg0, 0xCC) + 0x12D8, 0, 0x90);
    FLD(s32, FLD(void*, arg0, 0xCC), 0x25C) = r27;
    FLD(s32, FLD(void*, arg0, 0xCC), 0x260) = r26;

    s32 i = 0;
    off = 0;
    for (; i < FLD(s32, arg0, 0x104); i++) {
        m = FLD(u8, (u8*)FLD(void*, arg0, 0x44) + off, 0x9B) * 0x2AC;
        r = randi__Fl(0xFFFFFF);
        FLD(s32, (u8*)FLD(void*, arg0, 0xCC) + m, 0x2A0) = r;
        FLD(s32, (u8*)FLD(void*, arg0, 0xCC) + m, 0x2A4) = 7 - i;
        off += 0x5C;
    }

    k = 0;
    off = 0;
    do {
        FLD(s32, (u8*)FLD(void*, arg0, 0xCC) + off, 0x12FC) = randi__Fl(0xFFFFFF);
        FLD(s32, (u8*)FLD(void*, arg0, 0xCC) + off, 0x1300) = 7 - k++;
        off += 0x30;
    } while (k < 3);
}
