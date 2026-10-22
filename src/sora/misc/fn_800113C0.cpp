#pragma force_active on
typedef float f32;
typedef int s32;

extern "C" {
s32 fn_80041DCC(s32, f32 *, f32, f32, f32, f32);

s32 fn_800113C0(s32 arg0, s32 arg1)
{
    f32 vec[3];
    s32 var_r5;
    s32 temp_r0;
    f32 temp_f0, temp_f1, temp_f2, temp_f3, temp_f4;

    var_r5 = 0;
    temp_r0 = *(s32 *)(arg1 + 0x18);
    switch (temp_r0) {
    case 0:
        var_r5 = 1;
        break;
    case 1:
        temp_f4 = *(f32 *)(arg1 + 0x48);
        temp_f1 = *(f32 *)(arg1 + 0x20);
        temp_f3 = *(f32 *)(arg1 + 0x4C);
        temp_f0 = *(f32 *)(arg1 + 0x24);
        temp_f1 = temp_f4 + temp_f1;
        temp_f2 = *(f32 *)(arg1 + 0x50);
        vec[2] = temp_f2;
        vec[0] = temp_f1;
        vec[1] = temp_f3 + temp_f0;
        var_r5 = fn_80041DCC(arg0 + 0x2C, vec, temp_f1, temp_f2, temp_f3, temp_f4);
        break;
    }
    return var_r5;
}
}
