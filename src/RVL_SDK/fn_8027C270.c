#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

s32 fn_8027C270(void *arg0) {
    s32 temp_r5;
    s32 var_r4;

    temp_r5 = *(s32 *)((u8 *)arg0 + 0x48);
    var_r4 = 0;
    if (temp_r5 >= 0 && *(s32 *)((u8 *)arg0 + 0x44) <= temp_r5) {
        var_r4 = 1;
    }
    return var_r4 << 0x18;
}
