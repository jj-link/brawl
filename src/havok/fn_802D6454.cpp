#include <types.h>
#pragma force_active on
extern "C" {
void fn_8027C808(void*, void*, void*, u32, u32, u32, u32, u32, u32, u32, u32);
extern u8 lbl_80410F88[];
extern u8 lbl_80532730[];
extern u8 lbl_80532918[];
}
extern "C" void fn_802D6454() {
    fn_8027C808(lbl_80532918, lbl_80410F88, lbl_80532730, 0x10, 0, 0, 0, 0, 0, 0, 0);
}

__declspec(section ".ctors") extern void* const fn_802D6454_ctor = (void*)fn_802D6454;
