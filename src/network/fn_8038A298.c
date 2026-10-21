#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

s32 fn_8038A298(const u8 *arg0, s32 arg1) {
    s32 i = 0;
    while (arg1 > 0) {
        if ((s8)*arg0 == 0)
            return i + 1;
        i++;
        arg0++;
        arg1--;
    }
    return -1;
}
