#include <types.h>
#pragma force_active on

extern "C" void fn_8014E0DC(s32, s32);
extern "C" s32 fn_803A02A4(s32, s32, s32*, s32*);

extern "C" s32 fn_8014D598(s32 arg0, s32 arg1, s32* arg2) {
    s32 spC;
    s32 sp8;
    s32 result;

    *arg2 = 0;
    result = fn_803A02A4(arg1, 1, &spC, &sp8);
    if (result != 0) {
        fn_8014E0DC(arg0, result);
        return 0;
    }
    if (spC == 0) {
        return 0;
    }
    *arg2 = sp8;
    return 1;
}
