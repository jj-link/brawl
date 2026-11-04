#include <types.h>
#pragma force_active on

extern "C" {
extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern u8 lbl_80414D88[];
extern u8 lbl_80532340[];
extern u8 lbl_805334D8[];
}

extern "C" void fn_8032E890(void) {
    fn_8027C808(lbl_805334D8, lbl_80414D88, (u32)lbl_80532340, 8, 0, 0, 0, 0, 0, 0, 0);
}

__declspec(section ".ctors") extern void* const fn_8032E890_ctor = (void*)fn_8032E890;
