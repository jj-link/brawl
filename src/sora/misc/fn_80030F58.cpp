#pragma force_active on
typedef int s32;

extern "C" s32 fn_80032F38(s32, s32, s32);

extern "C" s32 fn_80030F58(s32 a) {
    return fn_80032F38(a, 2, 0);
}
