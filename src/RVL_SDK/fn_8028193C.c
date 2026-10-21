#include <types.h>
#pragma force_active on

s8 fn_8028193C(s8 arg0) {
    s32 var_r4;

    var_r4 = 0;
    if ((arg0 >= 0x41) && (arg0 <= 0x5A)) {
        var_r4 = 1;
    }
    if (var_r4 != 0) {
        return (s8)(arg0 + 0x20);
    }
    return arg0;
}
