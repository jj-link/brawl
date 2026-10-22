#include <types.h>
#pragma force_active on

extern "C" void fn_8027C808(void* p, void* a, void* b, u32 c, u32 d, u32 e, u32 f, u32 g, void* h, u32 i, u32 j);

extern char lbl_80413198[];
extern char lbl_804131C0[];
extern char lbl_805330B0[];
extern char lbl_80533128[];
extern char lbl_8053314C[];

extern "C" void fn_802E5A28(void) {
    fn_8027C808(lbl_80533128, lbl_804131C0, lbl_805330B0, 0x110, 0, 0, 0, 0, lbl_80413198, 2, 0);
    fn_8027C808(lbl_8053314C, lbl_804131C0 + 0x17, lbl_80533128, 0x110, 0, 0, 0, 0, 0, 0, 0);
}

__declspec(section ".ctors") extern void* const fn_802E5A28_ctor = (void*)fn_802E5A28;
