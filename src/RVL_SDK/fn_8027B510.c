#include <types.h>
#pragma force_active on

extern void fn_8027C808(void* p, void* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i, u32 j);
extern unsigned char lbl_8040E9E8[];
extern unsigned char lbl_80532318[];

void fn_8027B510(void) {
    fn_8027C808(lbl_80532318, lbl_8040E9E8, 0, 4, 0, 1, 0, 0, 0, 0, 0);
}

__declspec(section ".ctors") extern void* const fn_8027B510_ctor = (void*)fn_8027B510;
