#pragma force_active on
typedef int s32;

extern "C" {
s32 fn_41_15FD4(s32 a, s32 b);
s32 fn_41_1F0FC(s32 a, s32 b);

s32 fn_41_17CAC(s32 a, s32 b, s32 c) {
    if (b == -1) {
        return -1;
    }
    return fn_41_1F0FC(fn_41_15FD4(a, b), c);
}
}
