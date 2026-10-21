#include <types.h>
#pragma force_active on

s32 fn_8020F3F0(s32 *, s32);

s32 fn_8020FDA8(void) {
    s32 sp8;

    if (fn_8020F3F0(&sp8, 0) == 0) {
        sp8 = 0x0B49D800;
    }
    return sp8;
}
