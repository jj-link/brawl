#include <types.h>
#pragma force_active on
#pragma opt_propagation off
extern "C" void fn_80162C04(float* dst, const float* src) {
    int offset = 0;
    __vec2x32float__ a = *(const __vec2x32float__*)((const char*)src + offset);
    __vec2x32float__ b = *(const __vec2x32float__*)(src + 2);
    __vec2x32float__ c = *(const __vec2x32float__*)(src + 4);
    __vec2x32float__ d = *(const __vec2x32float__*)(src + 6);
    __vec2x32float__ e = *(const __vec2x32float__*)(src + 8);
    __vec2x32float__ f = *(const __vec2x32float__*)(src + 10);
    __vec2x32float__ g = *(const __vec2x32float__*)(src + 12);
    __vec2x32float__ h = *(const __vec2x32float__*)(src + 14);
    *(__vec2x32float__*)((char*)dst + offset) = a;
    *(__vec2x32float__*)(dst + 2) = b;
    *(__vec2x32float__*)(dst + 4) = c;
    *(__vec2x32float__*)(dst + 6) = d;
    *(__vec2x32float__*)(dst + 8) = e;
    *(__vec2x32float__*)(dst + 10) = f;
    *(__vec2x32float__*)(dst + 12) = g;
    *(__vec2x32float__*)(dst + 14) = h;
}
