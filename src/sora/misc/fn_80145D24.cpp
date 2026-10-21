#include <types.h>
#pragma force_active on

extern "C" void fn_80145D24(u32* p, u32 a, u32 b, u32 c, u32 d) {
    p[8] = a;
    p[9] = b;
    p[10] = c;
    p[11] = d;
}
