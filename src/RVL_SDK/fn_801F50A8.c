#include <types.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXInit.h>
#pragma force_active on
#pragma opt_propagation off

void fn_801F50A8(void) {
    __vec2x32float__* dst = (__vec2x32float__*)&WGPIPE;
    int off0 = 0;
    int off1 = 0;
    int off2 = 0;
    __vec2x32float__ c, b, a;

    WGPIPE.c = 0x10;
    WGPIPE.i = 0x61020;
    a = *(__vec2x32float__*)&__GXData->proj[0];
    b = *(__vec2x32float__*)&__GXData->proj[2];
    c = *(__vec2x32float__*)&__GXData->proj[4];
    *(__vec2x32float__*)((char*)dst + off0) = a;
    *(__vec2x32float__*)((char*)dst + off1) = b;
    *(__vec2x32float__*)((char*)dst + off2) = c;
    WGPIPE.i = __GXData->projType;
}
