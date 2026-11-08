#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on
extern void fn_801F0E10(void);
extern void fn_801D50A0(void);
void fn_801F0530(void) {
 if (__GXData->gxDirtyFlags != 0) fn_801F0E10();
 WGPIPE.i = 0;
 WGPIPE.i = 0;
 WGPIPE.i = 0;
 WGPIPE.i = 0;
 WGPIPE.i = 0;
 WGPIPE.i = 0;
 WGPIPE.i = 0;
 WGPIPE.i = 0;
 fn_801D50A0();
}
