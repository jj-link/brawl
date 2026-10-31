#include <types.h>
#pragma force_active on

extern char lbl_8053B248[];
extern void fn_803A9938(unsigned int, short *, short *);

s32 fn_803BED88(s32 arg0) {
    s16 locals[4];
    u32 var_r30 = 0;
    s32 var_r29 = 0;

    while (*(u16 *)(arg0 + var_r30 * 2) != 0) {
        fn_803A9938(
            (*(s32 (*)(s32, s32 *))(*(s32 *)(lbl_8053B248 + 0x28)))(
                arg0 + (s32)(var_r30 * 2), (s32 *)&locals[0]),
            &locals[3], &locals[2]);
        var_r29 += locals[3];
        var_r30 += (u32)(locals[2] >> 1);
    }
    return var_r29;
}
