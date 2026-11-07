#include <revolution/GX/GXInit.h>
#pragma force_active on
void fn_801F50EC(float m[3][4], GXProjectionType type)
{
    GXData *gx = __GXData;
    float a, b;
    b = (a = m[0][0], gx->projType = type, m[1][1]);
    gx->proj[0] = a;
    a = m[2][2];
    gx->proj[2] = b;
    b = m[2][3];
    gx->proj[4] = a;
    gx->proj[5] = b;
    if (type == 1) {
        b = (a = m[0][3], m[1][3]);
        gx->proj[1] = a; gx->proj[3] = b;
    } else {
        b = (a = m[0][2], m[1][2]);
        gx->proj[1] = a; gx->proj[3] = b;
    }
    gx->gxDirtyFlags |= 0x08000000;
}