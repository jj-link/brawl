#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXInit.h>
#pragma force_active on

void fn_801F55B0(char *arg0, char *arg1) {
    u32 cmd = 0;
    cmd = __rlwimi(cmd, (u32)arg0 + 0x156, 31, 22, 31);
    cmd = __rlwimi(cmd, (u32)arg1 + 0x156, 9, 12, 21);
    WGPIPE.c = 0x61;
    cmd = __rlwimi(cmd, 0x59, 24, 0, 7);
    WGPIPE.i = cmd;
    __GXData->lastWriteWasXF = 0;
}