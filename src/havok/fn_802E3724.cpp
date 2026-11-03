#include <types.h>
#pragma force_active on

extern "C" {
extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern u8 lbl_80412CF0[];
extern u8 lbl_80532F80[];
extern u8 lbl_80533008[];
}

extern "C" void fn_802E3724(void) {
    fn_8027C808(lbl_80533008, lbl_80412CF0, (u32)lbl_80532F80, 0x1F0, 0, 0, 0, 0, 0, 0, 0);
}

__declspec(section ".ctors") extern void* const fn_802E3724_ctor = (void*)fn_802E3724;
