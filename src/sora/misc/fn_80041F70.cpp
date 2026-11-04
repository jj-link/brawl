#pragma force_active on
#include <gf/gf_camera.h>
#include <gf/gf_draw.h>

extern float lbl_805A17A8;

extern "C" void fn_80041F70(float* arg0) {
    char buf[0x3b8];
    float k, x0, xc, x4, x8;

    ((gfCamera*)gfCameraManager::getManager())->setGX();
    gfDrawSetVtxPosColorPrimEnvironment();
    k = lbl_805A17A8;
    xc = arg0[3];
    x0 = arg0[0];
    x4 = arg0[1];
    x8 = arg0[2];
    *(float*)(buf + 0x30) = x0;
    *(float*)(buf + 0x34) = xc;
    *(float*)(buf + 0x38) = k;
    *(float*)(buf + 0x384) = x0;
    *(float*)(buf + 0x40) = xc;
    *(float*)(buf + 0x80) = k;
    *(float*)(buf + 0x24) = x0;
    *(float*)(buf + 0x28) = x4;
    *(float*)(buf + 0x2c) = k;
    *(float*)(buf + 0xc0) = x0;
    *(float*)(buf + 0x100) = x4;
    *(float*)(buf + 0x140) = k;
    *(float*)(buf + 0x18) = x8;
    *(float*)(buf + 0x1c) = x4;
    *(float*)(buf + 0x20) = k;
    *(float*)(buf + 0x180) = x8;
    *(float*)(buf + 0x1c0) = x4;
    *(float*)(buf + 0x200) = k;
    *(float*)(buf + 0xc) = x8;
    *(float*)(buf + 0x10) = xc;
    *(float*)(buf + 0x14) = k;
    *(float*)(buf + 0x240) = x8;
    *(float*)(buf + 0x280) = xc;
    *(float*)(buf + 0x2c0) = k;
    *(float*)(buf + 0x0) = x0;
    *(float*)(buf + 0x4) = xc;
    *(float*)(buf + 0x8) = k;
    *(float*)(buf + 0x300) = x0;
    *(float*)(buf + 0x340) = xc;
    *(float*)(buf + 0x380) = k;
    gfCameraManager::getManager();
}