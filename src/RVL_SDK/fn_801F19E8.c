#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

extern const float lbl_805A37D8;

typedef struct {
    unsigned opcode : 8;
    unsigned pad : 15;
    unsigned value : 9;
} Command;

typedef struct {
    unsigned a : 21;
    unsigned flag : 1;
    unsigned b : 10;
} State;

unsigned int fn_801F19E8(float f) {
    unsigned int value, divisor, height, result;

    value = (unsigned int)(lbl_805A37D8 / f);
    {
        Command reg = {0};

        divisor = value & 0x1FF;
        reg.value = value & 0x1FF;
        WGPIPE.uc = 0x61;
        reg.opcode = 0x4E;
        WGPIPE.ui = *(unsigned int*)&reg;
    }

    __GXData->lastWriteWasXF = 0;
    ((State*)((char*)__GXData + 0x23C))->flag =
        ((0x100 - divisor) | (divisor - 0x100)) >> 31;

    height = ((*(unsigned int*)((char*)__GXData + 0x234) >> 10) & 0x3FF) + 1;
    result = (((height - 1) << 8) / divisor) + 1;

    if (divisor > 0x80 && divisor < 0x100) {
        while (!(divisor & 1)) {
            divisor >>= 1;
        }
        if (height % divisor == 0) {
            result++;
        }
    }

    if (result > 0x400) {
        result = 0x400;
    }

    return result;
}
