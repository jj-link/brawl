#include <types.h>
#pragma force_active on

extern "C" void fn_800E5174(void*, u32);
extern "C" s32 g_IfMngr;
extern "C" const f32 lbl_27_rodata_4144;

extern "C" void fn_27_255D78(s32 a, s32 b, u32 c) {
    if (c == 0) {
        if (c != *(u8*)(a + b + 0x64) && *(u8*)(a + b + 0x6B) == 0) {
            s32 mgr = g_IfMngr;
            s32 e = *(s32*)(mgr + (*(u8*)(mgr + b + 0x68) << 2) + 0x4C);
            if (*(s32*)(e + 0x354) != 0) {
                fn_800E5174((void*)e, 0);
            }
            *(f32*)(a + b * 4 + 0x98) = lbl_27_rodata_4144;
        }
    }
    *(u8*)(a + b + 0x64) = c;
}