#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_9EE8C(u32* p) {
    return (s32)(((p[1] >> 11) & 0x3F) << 26) >> 27;
}
