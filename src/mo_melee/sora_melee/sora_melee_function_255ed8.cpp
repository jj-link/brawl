#include <types.h>
#pragma force_active on

extern "C" void fn_800E4D28(void* p, s32 x);
extern "C" s32 g_IfMngr;

extern "C" void fn_27_255ED8(s32 a, s32 b, s32 c) {
    if (c == 0) {
        if ((u32)c != *(u8*)(a + b + 0xB4)) {
            s32 mgr = g_IfMngr;
            s32 e = *(s32*)(mgr + (*(u8*)(mgr + b + 0x68) << 2) + 0x4c);
            if (*(u8*)(e + 0x350) != 0) {
                fn_800E4D28((void*)e, 0);
            }
            mgr = g_IfMngr;
            e = *(s32*)(mgr + (*(u8*)(mgr + b + 0x68) << 2) + 0x4c);
            if (*(s32*)(e + 0x2b0) != 0) {
                *(s32*)(e + 0x2b0) = 0;
            }
        }
    }
    *(u8*)(a + b + 0xB4) = c;
}
