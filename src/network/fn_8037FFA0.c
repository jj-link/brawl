#include <types.h>
#pragma force_active on
s32 fn_8037C104(void *, s32, s32);
s32 fn_8037C1C0(void *, void *, s32);
typedef struct { s16 a; s8 b; } Pair16;
s32 fn_8037FFA0(void *arg0, void *arg1) {
    Pair16 spC, sp8;
    s32 temp_r0, temp_r0_3, temp_r0_4, temp_r3, temp_r3_4, temp_r4, temp_r4_2, temp_r5, temp_r5_2, var_r29, var_r5;
    char *var_r6;
    var_r6 = *(char **)arg0;
    var_r5 = *(s32 *)(var_r6 + 0xc);
    if (var_r5 == 0) return 1;
    if (*(s32 *)((char *)arg1 + 0x194) == 0) {
loop_3:
        temp_r4 = *(s32 *)((char *)arg0 + 4);
        temp_r3 = fn_8037C104(arg1, *(s32 *)(var_r6 + 8) + temp_r4, var_r5 - temp_r4);
        if (temp_r3 == -1) return 0;
        var_r6 = *(char **)arg0;
        temp_r0 = *(s32 *)((char *)arg0 + 4) + temp_r3;
        *(s32 *)((char *)arg0 + 4) = temp_r0;
        var_r5 = *(s32 *)(var_r6 + 0xc);
        if (var_r5 == temp_r0) {
            if (*(s32 *)(*(char **)((char *)arg1 + 0x160) + 0x14) != 0) {
                spC.a = 0; spC.b = 0;
                temp_r5 = 4 - (*(s32 *)(*(char **)arg0 + 0xc) % 4);
                if ((temp_r5 != 4) && (temp_r5 > 0) && (fn_8037C1C0(arg1, &spC.a, temp_r5) == 0)) return 0;
            }
            return 1;
        }
        if (temp_r3 == 0) return 2;
        goto loop_3;
    }
loop_14:
    temp_r4_2 = *(s32 *)((char *)arg0 + 4);
    var_r29 = 0x3F01;
    temp_r0_3 = var_r5 - temp_r4_2;
    if (temp_r0_3 < 0x3F01) var_r29 = temp_r0_3;
    temp_r3_4 = fn_8037C1C0(arg1, (void *)(*(s32 *)(var_r6 + 8) + temp_r4_2), var_r29);
    if (temp_r3_4 == 0) return 0;
    var_r6 = *(char **)arg0;
    temp_r0_4 = *(s32 *)((char *)arg0 + 4) + var_r29;
    *(s32 *)((char *)arg0 + 4) = temp_r0_4;
    var_r5 = *(s32 *)(var_r6 + 0xc);
    if (var_r5 == temp_r0_4) {
        if (*(s32 *)(*(char **)((char *)arg1 + 0x160) + 0x14) != 0) {
            sp8.a = 0; sp8.b = 0;
            temp_r5_2 = 4 - (*(s32 *)(*(char **)arg0 + 0xc) % 4);
            if ((temp_r5_2 != 4) && (temp_r5_2 > 0) && (fn_8037C1C0(arg1, &sp8.a, temp_r5_2) == 0)) return 0;
        }
        return 1;
    }
    if (temp_r3_4 != 1) return 2;
    goto loop_14;
}