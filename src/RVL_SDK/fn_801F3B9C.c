#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

static u32 c0[5] = {0xc008f8af, 0xc008a89f, 0xc008ac8f, 0xc008fff8, 0xc008fffa};
static u32 c1[5] = {0xc008f80f, 0xc008089f, 0xc0080c8f, 0xc008fff8, 0xc008fff0};
static u32 a0[5] = {0xc108f2f0, 0xc108ffd0, 0xc108f2f0, 0xc108ffc0, 0xc108ffd0};
static u32 a1[5] = {0xc108f070, 0xc108ff80, 0xc108f070, 0xc108ffc0, 0xc108ff80};

void GXSetTevOp(s32 id, s32 mode) {
    u32 *ctmp;
    u32 *atmp;
    u32 tevReg;

    if (id == 0) {
        ctmp = c0 + mode;
        atmp = a0 + mode;
    } else {
        ctmp = c1 + mode;
        atmp = a1 + mode;
    }
    tevReg = ((u32 *)__GXData)[0x60 + id];
    tevReg = (*ctmp & 0x00FFFFFF) | (tevReg & 0xFF000000);
    GX_BP_LOAD_REG(tevReg);
    ((u32 *)__GXData)[0x60 + id] = tevReg;
    tevReg = ((u32 *)__GXData)[0x70 + id];
    tevReg = (*atmp & 0x00FFFFF0) | (tevReg & 0xFF00000F);
    GX_BP_LOAD_REG(tevReg);
    ((u32 *)__GXData)[0x70 + id] = tevReg;
    ((GXData *)__GXData)->lastWriteWasXF = 0;
}
