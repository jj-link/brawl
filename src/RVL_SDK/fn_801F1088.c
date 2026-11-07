#include <revolution/GX/GXGeometry.h>
#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

extern void fn_801F0E10(void);

static inline void flushPrim(void) {
    u32 i;
    u32 sz = gxdt->SHORT_0x4 * gxdt->vlim;

    WGPIPE.uc = GX_TRIANGLESTRIP;
    WGPIPE.us = gxdt->SHORT_0x4;

    for (i = 0; i < sz; i += 4) {
        WGPIPE.i = 0;
    }

    gxdt->lastWriteWasXF = TRUE;
}

void GXBegin(GXPrimitive prim, GXVtxFmt fmt, u16 verts) {
    if (gxdt->gxDirtyFlags != 0) {
        fn_801F0E10();
    }

    if (gxdt->WORD_0x0 == 0) {
        flushPrim();
    }

    WGPIPE.c = fmt | prim;
    WGPIPE.s = verts;
}
