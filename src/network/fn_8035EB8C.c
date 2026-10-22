#include <types.h>
#include <string.h>
#pragma force_active on

s32 fn_8035EB8C(u32 *arg0, u32 arg1) {
    if (arg1 > 0x40) {
        return 0;
    }
    if (*arg0 >= arg1) {
        while (*arg0 > arg1 && arg0[*arg0] == 0) {
            (*arg0)--;
        }
        if (*arg0 == arg1) {
            return 1;
        }
        return 0;
    }
    memset(arg0 + *arg0 + 1, 0, (arg1 - *arg0) * 4);
    *arg0 = arg1;
    return 1;
}
