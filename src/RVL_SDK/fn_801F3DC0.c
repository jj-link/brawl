#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

void fn_801F3DC0(u32 id, GXColorS10 color) {
    u32 a = *(u32 *)&color;
    u32 b = *((u32 *)&color + 1);
    u32 lo = __rlwimi(__rlwimi((id * 2 + 0xE0) << 24, a, 16, 21, 31), b, 12, 9, 19);
    u32 hi = __rlwimi(__rlwimi((id * 2 + 0xE1) << 24, b, 16, 21, 31), a, 12, 9, 19);
    GX_BP_LOAD_REG(lo);
    GX_BP_LOAD_REG(hi);
    GX_BP_LOAD_REG(hi);
    GX_BP_LOAD_REG(hi);
    gxdt->lastWriteWasXF = 0;
}