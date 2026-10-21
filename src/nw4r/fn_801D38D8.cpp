#include <types.h>
#pragma force_active on

extern "C" s32 fn_801D38D8(u32 arg0) {
    if (arg0 == 1U)
        return 10;

    s32 result = 0;
    if ((s32)arg0 == 0)
        result = 25;
    return result;
}
