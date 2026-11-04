#include <types.h>
#pragma force_active on

extern void *fn_80396EEC(void *a, void *b, int c);

void fn_8039738C(void *arg0, void *arg1) {
    void *temp_r3;
    void *var_r6;
    void *temp_r3_2;
    void *temp_r3_3;
    void *var_r3;
    s32 sp8;
    s32 spC;
    s32 sp10;
    s32 sp[3];

    if (fn_80396EEC(arg0, arg1, 0) != 0) {
        temp_r3 = fn_80396EEC(arg0, arg1, 0);
        if (temp_r3 != 0) {
            var_r6 = *(void **)((char *)temp_r3 + 0x14);
        } else {
            var_r6 = 0;
        }
        if (var_r6 != 0 && *(void **)((char *)arg1 + 0x1c) != 0) {
            sp[0] = *(s32 *)((char *)var_r6 + 0x28);
            sp[1] = *(s32 *)((char *)var_r6 + 0x1c);
            sp[2] = *(s32 *)((char *)var_r6 + 0x4);
            ((void (*)(void *, s32, s32 *))*(void **)((char *)arg1 + 0x1c))(arg1, 3, sp);
            sp10 = sp[2];
            spC = sp[1];
            sp8 = sp[0];
            temp_r3_2 = fn_80396EEC(arg0, arg1, 0);
            if (temp_r3_2 != 0) {
                temp_r3_3 = fn_80396EEC(arg0, temp_r3_2, 0);
                if (temp_r3_3 != 0) {
                    var_r3 = *(void **)((char *)temp_r3_3 + 0x14);
                } else {
                    var_r3 = 0;
                }
                if (var_r3 != 0) {
                    *(s32 *)((char *)var_r3 + 0x28) = sp8;
                    *(s32 *)((char *)var_r3 + 0x1c) = spC;
                    *(s32 *)((char *)var_r3 + 0x4) = sp10;
                }
            }
        }
    }
}
