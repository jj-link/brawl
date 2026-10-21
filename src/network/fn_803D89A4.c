#pragma force_active on
typedef int s32;

extern s32 fn_803D7B10(s32);

s32 fn_803D89A4(s32 *arg0) {
    s32 temp = fn_803D7B10(arg0[1]);
    return temp & ((-temp | temp) >> 31);
}
