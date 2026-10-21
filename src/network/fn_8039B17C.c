#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

s32 fn_8039B17C(void *arg0, u32 arg1, s32 *arg2) {
    if (arg1 >= 2 || arg1 >= ((u8 *)arg0)[0xC9]) {
        return -3;
    }
    *arg2 = *(s32 *)((u8 *)arg0 + 0x78 + arg1 * 4);
    return 0;
}
