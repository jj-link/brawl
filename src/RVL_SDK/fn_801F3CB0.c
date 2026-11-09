#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#pragma force_active on

void fn_801F3CB0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5)
{
    u32 value = ((u32*)__GXData->UNK_0x180)[arg0];

    value = __rlwimi(value, arg1, 18, 13, 13);
    if (arg1 <= 1) {
        value = __rlwimi(value, arg3, 20, 10, 11);
        value = __rlwimi(value, arg2, 16, 14, 15);
    } else {
        value = __rlwimi(value, arg1, 19, 10, 11);
        value |= 0x30000;
    }
    value = __rlwimi(value, arg4, 19, 12, 12);
    value = __rlwimi(value, arg5, 22, 8, 9);
    GX_BP_LOAD_REG(value);
    ((u32*)__GXData->UNK_0x180)[arg0] = value;
    __GXData->lastWriteWasXF = 0;
}
