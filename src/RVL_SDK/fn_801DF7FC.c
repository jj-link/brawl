#include <types.h>
#pragma force_active on

extern int lbl_804DD120[8];

u32 fn_801DF7FC(void) {
    if (lbl_804DD120[0] != 0) {
        return (u32)lbl_804DD120[1] | 0x80000000;
    }
    return *(u32 *)0xCC003024 >> 3;
}
