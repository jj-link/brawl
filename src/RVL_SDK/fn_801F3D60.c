#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

void fn_801F3D60(u32 id, const u32 *color) {
    u32 a = *(const u32 *)color;
    u32 lo = __rlwimi(__rlwimi((id * 2 + 0xE0) << 24, a, 8, 24, 31), a, 12, 12, 19);
    u32 hi = __rlwimi(__rlwimi((id * 2 + 0xE1) << 24, a, 24, 24, 31), a, 28, 12, 19);
    GX_BP_LOAD_REG(lo);
    GX_BP_LOAD_REG(hi);
    GX_BP_LOAD_REG(hi);
    GX_BP_LOAD_REG(hi);
    gxdt->lastWriteWasXF = 0;
}