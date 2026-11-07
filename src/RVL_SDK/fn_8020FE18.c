#include <types.h>
#pragma force_active on
extern int fn_8020F3F0(void *, u32);

u32 fn_8020FE18(void) {
    u32 sp8;
    if (fn_8020F3F0(&sp8, 0x1e) == 0) {
        sp8 = 2;
    } else if (sp8 < 1) {
        sp8 = 1;
    } else if (sp8 > 5) {
        sp8 = 5;
    }
    return sp8;
}