#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" {
u32 fn_800AE528(s32 *arg0, u32 arg1, u32 arg2, s32 *arg3) {
    s32 *p = arg0 + (s32)arg2;
    u32 count = 0;
    while (count < arg1 && count + arg2 < *(u32*)((u8*)arg0 + 0x2EF4)) {
        *arg3 = arg0[0] + p[0x1F9] * 0x64;
        p++;
        arg3++;
        count++;
    }
    return count;
}
}
