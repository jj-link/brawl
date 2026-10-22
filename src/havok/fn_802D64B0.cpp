#include <types.h>
#pragma force_active on

extern "C" {
void fn_8027C808(void* p, void* a, void* b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern u8 lbl_80410F98[];
extern u8 lbl_80532830[];
extern u8 lbl_80532940[];
}

extern "C" void fn_802D64B0() {
    fn_8027C808(lbl_80532940, lbl_80410F98, lbl_80532830, 0xC, 0, 0, 0, 0, 0, 0, 0);
}

__declspec(section ".ctors") extern void* const fn_802D64B0_ctor = (void*)fn_802D64B0;
