#include <types.h>
#pragma force_active on

extern void fn_801F28F0(void *, u32, u16, u16, u32, u32, u32, u8);

void fn_801F2AFC(void *arg0, u32 arg1, u16 arg2, u16 arg3, u32 arg4, u32 arg5, u32 arg6, u8 arg7, u32 arg8) {
    char *p = (char *)arg0;
    fn_801F28F0(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    *(u32 *)(p + 0x18) = arg8;
    p[0x1F] = p[0x1F] & ~2;
}
