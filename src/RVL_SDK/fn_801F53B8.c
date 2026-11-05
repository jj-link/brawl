#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/GX/GXHardwareXF.h>
#pragma force_active on

void fn_801F53B8(void) {
    f32 a, b, c, d, e, f;
    f32 near, far;

    a = gxdt->vpSx / 2.0f;
    b = -gxdt->vpSy / 2.0f;
    d = gxdt->vpOx + (gxdt->vpSx / 2.0f) + 342.0f;
    e = gxdt->vpOy + (gxdt->vpSy / 2.0f) + 342.0f;

    near = gxdt->vpNear * gxdt->scaleZ;
    far = gxdt->vpFar * gxdt->scaleZ;

    c = far - near;
    f = far + gxdt->offsetZ;

    GX_XF_LOAD_REGS(6 - 1, GX_XF_REG_SCALEX);
    WGPIPE.f = a;
    WGPIPE.f = b;
    WGPIPE.f = c;
    WGPIPE.f = d;
    WGPIPE.f = e;
    WGPIPE.f = f;
}