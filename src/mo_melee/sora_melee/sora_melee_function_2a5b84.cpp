#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_2A5EE0(u32, u32, u32, u32);

extern "C" u32 fn_27_2A5B84(u32 a, u32 b, u32 c) {
    u32 x = fn_27_2A5EE0(a, b, c, 0);
    return (-x | x) >> 31;
}
