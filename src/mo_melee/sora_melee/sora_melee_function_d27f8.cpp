#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_D27F8(s32* ptr) {
    s32 val = *(ptr + 2);
    return val >> 27;
}
