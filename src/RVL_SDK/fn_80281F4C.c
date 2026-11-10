#include <types.h>
#pragma force_active on

extern void fn_8027C808(void*, void*, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern char lbl_8040F6B8[];
extern char lbl_8040F6E0[];
extern char lbl_805324A8[];

void fn_80281F4C(void) {
    fn_8027C808(lbl_805324A8, lbl_8040F6E0, 0, 0x20, 0, 0, 0, 0, (u32)lbl_8040F6B8, 2, 0);
}

__declspec(section ".ctors") extern void* const fn_80281F4C_ctor = (void*)fn_80281F4C;
