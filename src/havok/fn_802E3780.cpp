#include <types.h>
#pragma force_active on

extern "C" {
extern void fn_8027C808(void* p, void* a, void* b, u32 c, u32 d, u32 e, void* f, u32 g, u32 h, u32 i, u32 j);
extern u8 lbl_80533030[];
extern u8 lbl_80412D8C[];
extern u8 lbl_80532FA8[];
extern u8 lbl_80412D80[];
}

extern "C" void fn_802E3780() {
    fn_8027C808(lbl_80533030, lbl_80412D8C, lbl_80532FA8, 8, 0, 0, lbl_80412D80, 1, 0, 0, 0);
}

__declspec(section ".ctors") extern void* const fn_802E3780_ctor = (void*)fn_802E3780;
