#include <revolution/GX.h>
#pragma force_active on
void fn_801F3E24(GXTevKColorID arg0, GXColor color) {
    u32 idx = arg0 * 2;
    u32 val = *(u32*)&color;
    u32 cmd0 = (idx + 0xE0) << 24;
    u32 cmd1 = (idx + 0xE1) << 24;
    cmd0 = __rlwimi(cmd0, val, 8, 24, 31);
    cmd0 = __rlwimi(cmd0, val, 12, 12, 19);
    cmd0 = __rlwimi(cmd0, 8, 20, 8, 11);
    cmd1 = __rlwimi(cmd1, val, 24, 24, 31);
    cmd1 = __rlwimi(cmd1, val, 28, 12, 19);
    cmd1 = __rlwimi(cmd1, 8, 20, 8, 11);
    GX_BP_LOAD_REG(cmd0);
    GX_BP_LOAD_REG(cmd1);
    __GXData->lastWriteWasXF = FALSE;
}