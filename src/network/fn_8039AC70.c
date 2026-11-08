#include <types.h>
#pragma force_active on

extern void fn_80399CC8(void *p);

s32 fn_8039AC70(void *arg0, char *arg1, s32 arg2) {
    u32 flags = *(u32 *)((u8 *)arg0 + 0x4);
    if (!(flags & 0x100) || (flags & 0x200)) {
        return -7;
    }
    if (arg1 == 0 || *arg1 == 0) {
        return -5;
    }
    if (arg1[arg2] != 0) {
        return -0x19;
    }
    fn_80399CC8((u8 *)arg0 + 0x40);
    return 0;
}
