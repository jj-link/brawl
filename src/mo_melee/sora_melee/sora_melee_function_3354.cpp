#include <types.h>
#pragma force_active on
#pragma optimization_level 1
#pragma scheduling off
extern "C" void fn_27_3354(u32* dst, const u32* src) {
    u32 b, a;
    a = src[0];
    b = src[1];
    dst[0] = a;
    dst[1] = b;
    dst[2] = src[2];
}
