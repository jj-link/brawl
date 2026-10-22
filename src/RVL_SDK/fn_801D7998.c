#pragma force_active on
typedef int s32;
typedef unsigned int u32;

void fn_801D7950(s32, s32, s32);

u32 fn_801D7998(s32 arg0, s32 arg1, u32 arg2) {
    u32 n = (arg2 + 0x1F) >> 5;
    u32 ret = (n + 0x7F) >> 7;
    s32 b = arg1;
    s32 a = arg0;
    while (n != 0) {
        if (n < 0x80) {
            fn_801D7950(a, b, n);
            n = 0;
        } else {
            fn_801D7950(a, b, 0);
            n -= 0x80;
            a += 0x1000;
            b += 0x1000;
        }
    }
    return ret;
}
