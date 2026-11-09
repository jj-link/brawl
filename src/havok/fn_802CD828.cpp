#include <types.h>
#pragma force_active on

extern "C" {
void fn_8027C808(void*, void*, void*, u32, u32, u32, u32, u32, u32, u32, u32);
extern u8 lbl_80532660[];
extern u8 lbl_80410250[];
extern u8 lbl_80532628[];
}

extern "C" void fn_802CD828() {
    fn_8027C808(lbl_80532660, lbl_80410250, lbl_80532628, 0x18, 0, 0, 0, 0, 0, 0, 0);
}

__declspec(section ".ctors") extern void* const fn_802CD828_ctor = (void*)fn_802CD828;
