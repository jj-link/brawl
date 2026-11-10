#include <types.h>
#pragma force_active on
extern "C" { extern char lbl_80454510[]; }
inline void clear50(u32* p) {
    for (int j = 0; j < 50; ++j) p[j] = 0;
}
extern "C" void fn_800783EC(u8* self) {
    u8* p7;
    u8* p8;
    s32 i;
    *(void**)(self + 0x14C4) = lbl_80454510;
    p7 = self;
    p8 = self;
    *(u32*)(self + 0x16c) = 0;
    *(u32*)(self + 0x170) = 0;
    *(u32*)(self + 0x178) = 0;
    *(u32*)(self + 0x17c) = 0;
    *(u32*)(self + 0x180) = 0;
    *(u32*)(self + 0x184) = 0;
    *(u32*)(self + 0x188) = 0;
    *(u8*)(self + 0x18C) = 0;
    *(u32*)(self + 0x190) = 0x26FA;
    *(u32*)(self + 0x14c8) = 0;
    *(u32*)(self + 0x14cc) = 0;
    *(u32*)(self + 0x14d0) = 0;
    *(u32*)(self + 0x14d4) = 0;
    for (i = 0; i < 24; i++) {
        *(u32*)(p7 + 0x19C) = 0;
        clear50((u32*)(p8 + 0x1FC));
        p7 += 4;
        p8 += 0xC8;
    }
    *(u32*)(self + 0x14BC) = 0;
    *(u32*)(self + 0x14C0) = 0;
}