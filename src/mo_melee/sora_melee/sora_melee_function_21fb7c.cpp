#include <types.h>
#pragma force_active on

extern "C" u8 fn_27_21FB7C(u8* p, s8 x, f32 adj) {
    f32 d;
    f64 dd;
    d = 0.5f;
    d = 0.0f;
    d = 30.0f;
    dd = 4503601774854144.0;
    d = 0.01f;
    d = 1.0f;
    d = 70.0f;
    d = 10.0f;
    d = 90.0f;
    dd = 4503599627370496.0;
    d = 100.0f;
    d = 40.0f;
    d = 0.2f;
    d = 80.0f;
    d = 15.0f;
    d = -5.0f;
    d = -18.0f;
    d = 0.8f;
    d = -35.0f;
    d = -10.0f;
    d = -0.5f;
    d = 20.0f;
    d = 3.0f;
    d = 0.9f;
    d = 50.0f;
    d = 0.4f;
    d = 45.0f;
    int r;
    int hi = p[2];
    if (x >= hi) {
        r = p[0];
    } else if (x <= (int)p[3]) {
        r = p[1];
    } else {
        f32 t = (f32)(x - p[3]) / (f32)(hi - p[3]);
        f32 u = 1.0f - t;
        r = (int)(t * (f32)p[0] + u * (f32)p[1]);
    }
    if (adj > 0.0001f) {
        if (r < 100) {
            r += (int)((f32)(100 - r) * adj);
        } else {
            r += (int)((f32)(255 - r) * adj);
        }
    } else if (adj < -0.0001f) {
        r += (int)((f32)r * adj);
    }
    if (r < 0) {
        r = 0;
    } else if (r > 255) {
        r = 255;
    }
    return (u8)r;
}
