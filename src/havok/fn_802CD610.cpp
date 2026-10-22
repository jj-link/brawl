#include <types.h>
#pragma force_active on

extern "C" {
extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern u8 lbl_80410220[];
extern u8 lbl_80532340[];
extern u8 lbl_80532628[];
}

extern "C" void fn_802CD610() {
    fn_8027C808(lbl_80532628, lbl_80410220, (u32)lbl_80532340, 0x18, 0, 4, 0, 0, 0, 0, 0);
}

__declspec(section ".ctors") extern void* const fn_802CD610_ctor = (void*)fn_802CD610;
