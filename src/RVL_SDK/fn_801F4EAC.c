#include <types.h>
#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on
extern void fn_801F0E10(void);
extern void fn_801F11D4(void);
static inline void prepare(void) {
    GXData *gx = __GXData;
    if (gx->gxDirtyFlags != 0) fn_801F0E10();
    if (gx->WORD_0x0 == 0) fn_801F11D4();
}
void fn_801F4EAC(s32 arg0, s32 arg1) {
    prepare();
    WGPIPE.c = 0x40;
    WGPIPE.i = arg0;
    WGPIPE.i = arg1;
}