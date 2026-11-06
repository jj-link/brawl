#include <types.h>
#pragma force_active on

s32 fn_801E00A8(s32 *);
u32 fn_801FB338(void);

s32 fn_801DF2AC(u32 arg0) {
    s32 sp8;

    if (fn_801FB338() != 2U) {
        return 3;
    }
    if ((arg0 != 1U) || ((fn_801E00A8(&sp8) != 0) && (sp8 != 0))) {
        return 2;
    }
    return 1;
}
