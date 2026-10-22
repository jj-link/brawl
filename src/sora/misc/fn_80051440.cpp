#pragma force_active on
typedef signed int s32;
typedef unsigned int u32;

extern "C" {
s32 *fn_8004E604(s32);
s32 *fn_8004E610(s32);
extern s32 g_GameGlobal;

s32 fn_80051440(u32 arg0) {
    s32 *temp_r31;
    s32 *temp_r3;
    s32 temp_r5;
    s32 var_r4;
    s32 var_r4_2;
    s32 temp_r5_2;

    temp_r31 = fn_8004E604(g_GameGlobal);
    temp_r3 = fn_8004E610(g_GameGlobal);
    temp_r5 = *temp_r31;
    var_r4 = 0x1869F;
    if ((u32) (0x1869F - temp_r5) > arg0) {
        var_r4 = temp_r5 + arg0;
    }
    *temp_r31 = var_r4;
    var_r4_2 = -1;
    temp_r5_2 = *temp_r3;
    if ((u32) (-1 - temp_r5_2) > arg0) {
        var_r4_2 = temp_r5_2 + arg0;
    }
    *temp_r3 = var_r4_2;
    return *temp_r31;
}
}
