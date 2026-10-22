#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_80412B18[];
extern u8 lbl_80412C58[];
extern u8 lbl_80412C9C[];
extern u8 lbl_80532F80[];
extern u8 lbl_80533238[];
void fn_8027C808(void* p, void* a, void* b, u32 c, u32 d, u32 e, u32 f, u32 g, void* h, u32 i, void* j);
}

extern "C" void fn_802E1FCC(void) {
    fn_8027C808(lbl_80532F80, lbl_80412C9C, lbl_80533238, 0x1F0, 0, 0, 0, 0, lbl_80412B18, 0x10, lbl_80412C58);
}

__declspec(section ".ctors") extern void* const fn_802E1FCC_ctor = (void*)fn_802E1FCC;
