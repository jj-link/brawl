#include <types.h>
#pragma force_active on

extern "C" int* fn_8004E6B8(void* arg0);
extern "C" void* g_GameGlobal;

extern "C" void fn_800533C8(u32 arg0) {
    u32* temp_r3;
    s32 var_r5;
    u32 var_r0;

    temp_r3 = (u32*)fn_8004E6B8(g_GameGlobal);
    var_r5 = 0;
    if ((arg0 > 0x157529FFU) || (*temp_r3 > (u32)(0x157529FFU - arg0))) {
        var_r5 = 1;
    }
    if (var_r5 != 0) {
        var_r0 = 0x157529FFU;
    } else {
        var_r0 = *temp_r3 + arg0;
    }
    *temp_r3 = var_r0;
}
