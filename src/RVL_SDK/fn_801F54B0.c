#include <revolution/GX/GXInit.h>
#pragma force_active on
#pragma opt_propagation off
void fn_801F54B0(f32* dst)
{
    int offset = 0;
    __vec2x32float__ c, b, a;
    a = *(__vec2x32float__*)((unsigned char*)__GXData + 0x544);
    b = *(__vec2x32float__*)((unsigned char*)__GXData + 0x54C);
    c = *(__vec2x32float__*)((unsigned char*)__GXData + 0x554);
    *(__vec2x32float__*)((char*)dst + offset) = a;
    *(__vec2x32float__*)(dst + 2) = b;
    *(__vec2x32float__*)(dst + 4) = c;
}
