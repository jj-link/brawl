#include <revolution/GX/GXInit.h>
#pragma force_active on
#pragma opt_propagation off
#pragma opt_common_subs off
extern f32 lbl_805A38D0;
extern f32 lbl_805A38D4;
void fn_801F519C(f32* dst)
{
    __vec2x32float__ c, b, a;
    dst[0] = (__GXData->projType != 0) ? lbl_805A38D4 : lbl_805A38D0;
    a = *(__vec2x32float__*)((unsigned char*)__GXData + 0x52C);
    b = *(__vec2x32float__*)((unsigned char*)__GXData + 0x534);
    c = *(__vec2x32float__*)((unsigned char*)__GXData + 0x53C);
    *(__vec2x32float__*)(dst + 1) = a;
    *(__vec2x32float__*)(dst + 3) = b;
    *(__vec2x32float__*)(dst + 5) = c;
}
