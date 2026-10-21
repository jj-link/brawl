#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

s32 fn_80397664(u8 *arg0, u32 arg1) {
    s32 count = 0;

    while (count < arg1) {
        if ((s8)*arg0 == 0) {
            break;
        }
        count++;
        arg0++;
    }

    return count;
}
