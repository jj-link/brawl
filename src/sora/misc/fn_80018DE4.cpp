#include <gf/gf_camera.h>
#pragma force_active on

extern "C" {
void fn_801F5500(int, int, int, int);
void fn_801F5484(float, float, float, float, float, float);
void fn_801F55B0(void*, void*);
void fn_801ECF4C(void*, float, float, float, float, float, float);
void fn_801ECE60(void*, float, float, float, float);
void fn_801F50EC(void*, int);
void fn_801F51DC(void*, int);
void fn_801F52E4(int);
extern float lbl_805A1434;
}

void gfCamera::setGX() {
    float* f = (float*)this;
    unsigned short* h = (unsigned short*)this;
    int* i = (int*)this;
    char sp8[0x40];

    fn_801F5500(h[0x96], h[0x97], h[0x98], h[0x99]);
    fn_801F5484(f[0x45], f[0x46], f[0x47], f[0x48], f[0x49], f[0x4A]);
    fn_801F55B0(0, 0);
    if (i[0x40] == 0) {
        fn_801ECF4C(sp8, f[0x3A], f[0x3B], f[0x3C], f[0x3D], f[0x37], f[0x38]);
        fn_801F50EC(sp8, 1);
    } else {
        fn_801ECE60(sp8, lbl_805A1434 * f[0x36], f[0x39], f[0x37], f[0x38]);
        fn_801F50EC(sp8, 0);
    }
    fn_801F51DC(this, 0);
    fn_801F52E4(0);
}
