#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXTypes.h>
#pragma force_active on

void fn_801F48DC(GXBool arg0, GXBool arg1) {
    u32 reg = 0;
    reg = GX_BITSET(reg, 31, 1, arg1);
    reg = GX_BITSET(reg, 30, 1, arg0);
    GX_BP_SET_OPCODE(reg, 0x44);
    GX_BP_LOAD_REG(reg);
    gxdt->lastWriteWasXF = FALSE;
}
