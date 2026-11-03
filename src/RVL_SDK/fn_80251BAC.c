#include <types.h>
#pragma force_active on

s32 fn_80251BAC(u8* arg0) {
    u8* temp_r4;
    u8 var_r5 = 0;

    if (arg0[0x24] != 0 ||
        (temp_r4 = *(u8**)(arg0 + 0x6C)) == NULL ||
        temp_r4[0x71] == 0 ||
        *(u32*)(arg0 + 0x28) > 0x1F40 ||
        *(u16*)(arg0 + 0x20) > 0x10) {
        var_r5 = 1;
    }
    if (arg0[0x25] == var_r5) {
        return 0;
    }
    arg0[0x25] = var_r5;
    if (var_r5 != 0) {
        return 0x10000;
    }
    return 0x30000;
}
