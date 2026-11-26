#pragma force_active on
#include <types.h>

extern "C" void fn_8019DFAC(void *arg0, const void *arg1, u32 arg2) {
    f64 *dst = (f64 *)arg0;
    const f64 *src = (const f64 *)arg1;
    u32 n = arg2 >> 5;
    for (; n != 0; n--) {
        f64 a = src[0];
        f64 b = src[1];
        dst[0] = a;
        a = src[2];
        dst[1] = b;
        b = src[3];
        dst[2] = a;
        dst[3] = b;
        dst += 4;
        src += 4;
    }
}
