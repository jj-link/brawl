#include <types.h>
#pragma force_active on

extern "C" void fn_27_21DB30(void* a, s8 b, int c, int d);

extern "C" void fn_27_1F1B68(u8* self, s32 idx, s32 val) {
    u8* obj;
    u8* sub;

    if (self + 0x4C != 0 && idx >= 0 && idx < 7) {
        obj = *(u8**)(self + (idx << 2) + 0x4C);
        if (obj != 0 && (*(u8*)(self + 0xA0) == 1 || (s8)self[idx + 0x99] < 0)) {
            sub = *(u8**)(obj + 0x34);
            fn_27_21DB30(obj + 0x90, (s8)val, 0, (*(u16*)(obj + 0x3C) >> 15) & 1);
            if (sub != 0) {
                fn_27_21DB30(sub + 0x90, (s8)val, 0, (*(u16*)(sub + 0x3C) >> 15) & 1);
            }
        }
    }
}
