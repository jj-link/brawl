#include <types.h>
#pragma force_active on

extern "C" void* fn_8004E6A0(void*);
extern "C" void* fn_8004E6AC(void*);
extern "C" void* g_GameGlobal;

extern "C" void fn_800532F0(u32 arg0, s32 arg1) {
    u32* temp_r3;
    u32* temp_r3_2;
    s32 var_r5;
    s32 var_r5_2;
    u32 temp_r6;
    u32 var_r0;
    u32 var_r0_2;

    temp_r3 = (u32*)fn_8004E6A0(g_GameGlobal);
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
    temp_r3_2 = (u32*)fn_8004E6AC(g_GameGlobal);
    temp_r6 = arg0 * arg1;
    var_r5_2 = 1;
    if ((temp_r6 <= 0x157529FFU) && (*temp_r3_2 <= (u32)(0x157529FFU - temp_r6))) {
        var_r5_2 = 0;
    }
    if (var_r5_2 != 0) {
        var_r0_2 = 0x157529FFU;
    } else {
        var_r0_2 = *temp_r3_2 + temp_r6;
    }
    *temp_r3_2 = var_r0_2;
}