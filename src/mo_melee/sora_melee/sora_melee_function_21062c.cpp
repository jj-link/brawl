#include <types.h>
#pragma force_active on

extern "C" void fn_27_21062C(u8* self, u8* a1, u8* a2, f32 f1, f32 f2) {
    *(f32*)(self + 0xE0) = f1;
    *(f32*)(self + 0xE4) = f2;
    if (a1 != 0) {
        *(f32*)(self + 0xE8) = *(f32*)(a1 + 0x18);
        *(f32*)(self + 0xEC) = *(f32*)(a1 + 0x1C);
        *(f32*)(self + 0xF0) = *(f32*)(a1 + 0x20);
        *(f32*)(self + 0xF4) = *(f32*)(a1 + 0x24);
        if (*(u8**)(a1 + 0x44) == 0) {
            *(s32*)(self + 0xF8) = 0;
            *(s32*)(self + 0xFC) = 0;
        } else {
            *(s32*)(self + 0xFC) = *(s32*)(a1 + 0x48);
            *(s32*)(self + 0xF8) = *(s32*)(*(u8**)(a1 + 0x44) + 0x1C);
        }
    } else {
        *(s32*)(self + 0xF8) = 0;
    }
    if (a2 != 0) {
        if (*(u8**)(a2 + 0x44) == 0) {
            *(s32*)(self + 0x100) = 0;
            *(s32*)(self + 0x104) = 0;
            return;
        }
        *(s32*)(self + 0x104) = *(s32*)(a2 + 0x48);
        *(s32*)(self + 0x100) = *(s32*)(*(u8**)(a2 + 0x44) + 0x1C);
        return;
    }
    *(s32*)(self + 0x100) = 0;
}
