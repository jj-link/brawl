#pragma force_active on
typedef int s32;
typedef unsigned char u8;

s32 fn_803A71B0();
extern s32 lbl_805A1044;

s32 accept(s32 unused, u8 *arg1, s32 *arg2) {
    s32 temp_r3;

    *arg1 = (u8) *arg2;
    temp_r3 = fn_803A71B0();
    *arg2 = *arg1;
    if (temp_r3 >= 0) {
        return temp_r3;
    }
    lbl_805A1044 = temp_r3;
    return -1;
}
