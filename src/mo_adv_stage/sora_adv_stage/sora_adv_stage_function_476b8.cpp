#pragma force_active on
#include <types.h>

extern "C" {
void exit__6gfTaskFv(void* task);
unsigned char fn_800BA3D8(void* a, void* b);
void* fn_800BEEB8(int a1, int a2, int a3, void* a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
}

extern "C" s32 fn_40_476B8(u8* self) {
    u8* p = self + *(s32*)(self + 0x1414) * 0x58;
    s32 mode = 9;
    if ((p[0x1C0] >> 7) & 1) {
        mode = 0xB;
    }
    u8* p1888 = *(u8**)(self + 0x1888);
    s32 r30 = *(s32*)(self + 0x1560);
    s32 r29 = *(s32*)(p1888 + 4);
    s32 b = fn_800BA3D8(self + 0x100, p1888) & 0xFF;
    void* task = fn_800BEEB8(1, r29, mode, self + 0x147C, r30, *(s32*)(self + 0x143C), 0,
                             *(s32*)(self + 0x1AC), *(s32*)(self + 0x1B0), 0, 0, b);
    void* old = *(void**)(self + 0x188C);
    if (old != 0) {
        exit__6gfTaskFv(old);
    }
    *(void**)(self + 0x188C) = task;
    return 1;
}
