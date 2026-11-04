#include <types.h>
#pragma force_active on

s32 fn_8028193C(s8 arg0);

s32 fn_80281AEC(char* arg0, char* arg1) {
    s8 temp;
    s8 temp2;
    s32 i;

    for (i = 0; (arg0[i] != 0) || (arg1[i] != 0); i++) {
        temp = fn_8028193C((s8)arg1[i]);
        if ((s8)fn_8028193C((s8)arg0[i]) < temp) {
            return -1;
        }
        temp2 = fn_8028193C((s8)arg1[i]);
        if ((s8)fn_8028193C((s8)arg0[i]) > temp2) {
            return 1;
        }
    }
    return 0;
}
