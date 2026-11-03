#include <types.h>
#include <mt/mt_matrix.h>
#include <gf/gf_camera.h>
#include <revolution/GX/GXHardware.h>

#pragma force_active on

extern "C" {

void fn_801F52E4(int);
void fn_801F51DC(Matrix*, unsigned int);
void fn_801EFB10(void);
void fn_801EF280(int, int);
void fn_801EFB44(int, int, int, int, int);
void GXSetZMode(int, int, int);
void GXSetBlendMode(int, int, int, int);
void GXBegin(int, int, int);
void gfDrawSetVtxPosColorPrimEnvironment__Fv(void);

extern const float lbl_805A1948;
extern const float lbl_805A194C;
extern const float lbl_805A1950;

}

extern "C" void fn_8005E438(int unused, u32* arg1) {
    Matrix sp8(true);
    sp8.setIdentity();

    float hx = lbl_805A1948;
    float hy = lbl_805A194C;
    float hz = hx;

    gfDrawSetVtxPosColorPrimEnvironment__Fv();
    gfCameraManager* mgr = gfCameraManager::getManager();
    mgr->getCamera(0)->setGX();
    float dist = mgr->getCamera(0)->m_near;
    if (dist >= hx) {
        hz = lbl_805A1950 + dist;
        float k = hz / hx;
        hx = hx * k;
        hy = hy * k;
    }

    fn_801F52E4(0);
    fn_801F51DC(&sp8, 0);
    fn_801EFB10();
    fn_801EF280(9, 1);
    fn_801EF280(0xB, 1);
    fn_801EFB44(1, 9, 1, 4, 0);
    fn_801EFB44(1, 0xB, 1, 5, 0);
    GXSetZMode(0, 7, 0);
    u32 color = *arg1;
    GXSetBlendMode(1, 4, 5, 0);
    GXBegin(0x98, 1, 4);

    WGPIPE.f = -hx;
    WGPIPE.f = hy;
    WGPIPE.f = -hz;
    WGPIPE.ui = color;
    WGPIPE.f = hx;
    WGPIPE.f = hy;
    WGPIPE.f = -hz;
    WGPIPE.ui = color;
    WGPIPE.f = -hx;
    WGPIPE.f = -hy;
    WGPIPE.f = -hz;
    WGPIPE.ui = color;
    WGPIPE.f = hx;
    WGPIPE.f = -hy;
    WGPIPE.f = -hz;
    WGPIPE.ui = color;
}
