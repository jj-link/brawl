#include <types.h>
#pragma force_active on

extern u64 OSGetTime(void);
extern void *lbl_805A0FB0;

void fn_8034EB34(s32 arg0) {
    u64 t = OSGetTime();
    char *p = (char *)lbl_805A0FB0 + arg0 * 0x48;
    *(u32 *)(p + 0x44) = (u32)t;
    *(u32 *)(p + 0x40) = (u32)(t >> 32);
}
