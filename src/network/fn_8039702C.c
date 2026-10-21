#pragma force_active on
typedef int s32;

s32 fn_80396EEC(s32 a, s32 b, s32 c);

s32 fn_8039702C(s32 a, s32 b) {
    s32 temp_r3;

    temp_r3 = fn_80396EEC(a, b, 4);
    return (s32) ~(temp_r3 | -temp_r3) >> 0x1F;
}
