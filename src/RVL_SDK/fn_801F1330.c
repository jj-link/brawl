#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

typedef struct TxcReg {
    unsigned int pad0 : 12;
    unsigned int f12 : 1;
    unsigned int f13 : 1;
    unsigned int rest : 18;
} TxcReg;

void fn_801F1330(int arg0, int arg1, int arg2) {
    TxcReg *r = (TxcReg *)((char *)gxdt + 0x108 + arg0 * 4);
    r->f13 = arg1;
    r->f12 = arg2;
    WGPIPE.uc = 0x61;
    WGPIPE.ui = *(unsigned int *)r;
    gxdt->lastWriteWasXF = 0;
}
