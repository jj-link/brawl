#include <types.h>
#pragma force_active on

extern "C" float lbl_805A33E4;

extern "C" s32 fn_801AB384(void* arg0) {
    u8* p = (u8*)arg0;
    f32 x = *(f32*)(p + 0xDC);
    s32 result;

    if (x == *(f32*)(p + 0xE0) &&
        *(f32*)(p + 0xE0) == *(f32*)(p + 0xE4)) {
        if (lbl_805A33E4 == x) {
            result = 0;
        } else {
            result = 1;
        }
    } else {
        result = 2;
    }

    return result;
}
