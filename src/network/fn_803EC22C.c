#pragma force_active on
typedef int s32;
typedef signed char s8;

s32 fn_803EBA18(s8 arg0);

s32 fn_803EC22C(s8 arg0) {
    s32 x = fn_803EBA18(arg0);
    if (x == -1) {
        return -1;
    } else if (x == 1) {
        return 1;
    } else {
        x = (s32)((-x | x) >> 31);
        return x;
    }
}
