#include <revolution/GX/GXBump.h>
#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXTypes.h>
#pragma force_active on

void fn_801F4910(u32 arg0, u32 arg1) {
    gxdt->linePtWidth = __rlwimi(gxdt->linePtWidth, arg1, 22, 9, 9);
    *(u8*)0xCC008000 = 0x61;
    *(u32*)0xCC008000 = gxdt->linePtWidth;
    __GXFlushTextureState();
    *(u8*)0xCC008000 = 0x61;
    *(u32*)0xCC008000 = arg0 | 0x68000000;
    __GXFlushTextureState();
}