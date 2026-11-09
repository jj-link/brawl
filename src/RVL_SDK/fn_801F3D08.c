#include <types.h>
#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>

#pragma force_active on

void fn_801F3D08(s32 arg0, s32 arg1, s32 arg2,
                 s32 arg3, s32 arg4, s32 arg5)
{
    u32 value = ((u32*)__GXData->UNK_0x180)[arg0 + 16];

    value = __rlwimi(value, arg1, 18, 13, 13);

    if (arg1 <= 1) {
        value = __rlwimi(value, arg3, 20, 10, 11);
        value = __rlwimi(value, arg2, 16, 14, 15);
    } else {
        value = __rlwimi(value, arg1, 19, 10, 11);
        value |= 0x30000;
    }

    WGPIPE.uc = 0x61;
    value = __rlwimi(value, arg4, 19, 12, 12);
    value = __rlwimi(value, arg5, 22, 8, 9);
    WGPIPE.ui = value;

    ((u32*)__GXData->UNK_0x180)[arg0 + 16] = value;
    __GXData->lastWriteWasXF = 0;
}
