#include <types.h>
#pragma force_active on

extern "C" int fn_1_16BDC(void*);

extern "C" int fn_1_1B600(u8* self) {
    int ret = fn_1_16BDC(self);
    u32* s = *(u32**)(self + 0x54);
    if (s != 0) {
        u32* q = *(u32**)((u8*)s + 0xCC);
        *(u32**)(self + 0x100) = q;
        if (q != 0) {
            u32* h = *(u32**)(self + 0x98);
            if (h != 0) {
                *(u8*)((u8*)q + 0x668) = *(u8*)((u8*)h + 0x50);
            }
            *(u8*)(self + 0x104) = *(u8*)((u8*)*(u32**)(self + 0x100) + 0x669);
        }
    }
    return ret;
}
