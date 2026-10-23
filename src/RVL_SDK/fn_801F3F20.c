#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

typedef struct Reg {
    unsigned int rest : 28;
    unsigned int f29 : 2;
    unsigned int f31 : 2;
} Reg;

void fn_801F3F20(int arg0, int arg1, int arg2) {
    Reg *r = (Reg *)((char *)gxdt + 0x1C0 + arg0 * 4);
    r->f31 = arg1;
    r->f29 = arg2;
    WGPIPE.uc = 0x61;
    WGPIPE.ui = *(unsigned int *)r;
    gxdt->lastWriteWasXF = 0;
}
