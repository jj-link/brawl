#pragma force_active on
#include <types.h>

extern void *fn_8022EFF8(int);
extern void fn_80242908(void *p);

s32 fn_8024685C(void) {
    u8 *p;

    p = fn_8022EFF8(2);
    if (p == NULL) {
        return 0;
    }
    *(u16 *)(p + 2) = 3;
    *(u16 *)(p + 4) = 0;
    p[8] = 3;
    p[9] = 0x10;
    p[10] = 0;
    fn_80242908(p);
    return 1;
}
