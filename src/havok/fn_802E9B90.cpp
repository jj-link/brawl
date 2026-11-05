#include <types.h>
#pragma force_active on

extern "C" {
extern u8 lbl_80413308[];
extern u8 lbl_80413398[];
extern u8 lbl_804133B8[];
extern u8 lbl_80532340[];
extern u8 lbl_805331D8[];
void fn_8027C808(void* p, void* a, void* b, u32 c, u32 d, u32 e, u32 f, u32 g, void* h, u32 i, void* j);
}

extern "C" void fn_802E9B90(void) {
    fn_8027C808(lbl_805331D8, lbl_804133B8, lbl_80532340, 0x44, 0, 0, 0, 0, lbl_80413308, 7, lbl_80413398);
}

__declspec(section ".ctors") extern void* const fn_802E9B90_ctor = (void*)fn_802E9B90;
