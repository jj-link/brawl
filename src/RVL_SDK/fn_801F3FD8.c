#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXTev.h>
#pragma force_active on

void GXSetAlphaCompare(GXCompare comp0, u8 ref0, GXAlphaOp op, GXCompare comp1, u8 ref1) {
    u8* fifo = (u8*)0xCC008000;
    u32 reg;
    *fifo++ = 0x61;
    reg = 0xF3000000;
    reg |= ref0;
    reg = (reg & ~0xFF00) | ((ref1 << 8) & 0xFF00);
    reg = (reg & ~0x70000) | ((comp0 << 16) & 0x70000);
    reg = (reg & ~0x380000) | ((comp1 << 19) & 0x380000);
    reg = (reg & ~0xC00000) | ((op << 22) & 0xC00000);
    *(u32*)(fifo - 1) = reg;
    __GXData->lastWriteWasXF = 0;
}