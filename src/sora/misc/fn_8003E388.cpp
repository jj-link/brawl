#include <types.h>
#pragma force_active on

#pragma opt_propagation off

extern "C" void fn_8003E388(const f32* src, f32* dst)
{
    int offset = 0;
    const __vec2x32float__ f0 = *(const __vec2x32float__*)((const char*)src + offset);
    const __vec2x32float__ f1 = *(const __vec2x32float__*)(src + 2);
    const __vec2x32float__ f2 = *(const __vec2x32float__*)(src + 4);
    const __vec2x32float__ f3 = *(const __vec2x32float__*)(src + 6);
    const __vec2x32float__ f4 = *(const __vec2x32float__*)(src + 8);
    const __vec2x32float__ f5 = *(const __vec2x32float__*)(src + 10);
    *(__vec2x32float__*)((char*)dst + offset) = f0;
    *(__vec2x32float__*)(dst + 2) = f1;
    *(__vec2x32float__*)(dst + 4) = f2;
    *(__vec2x32float__*)(dst + 6) = f3;
    *(__vec2x32float__*)(dst + 8) = f4;
    *(__vec2x32float__*)(dst + 10) = f5;
}
