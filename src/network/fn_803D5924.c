#include <types.h>
#pragma force_active on

extern void fn_803D5014(void *a, void *b);
extern int fn_803D521C(void *p);

int fn_803D5924(void *arg0, u8 *arg1, u32 arg2) {
    u8 *temp;

    if (arg1 == 0) {
        return 0;
    }
    if (arg2 >= *(u16 *)(arg1 + 0xC)) {
        return 0;
    }
    if (*(u16 *)(arg1 + 0xE) == 0) {
        return 0;
    }
    temp = *(u8 **)(arg1 + 0x8) + ((arg2 << 6) & 0x3FFFC0);
    if (fn_803D521C(temp + 0x18) == 0) {
        return 0;
    }
    fn_803D5014(temp, arg0);
    return 1;
}
