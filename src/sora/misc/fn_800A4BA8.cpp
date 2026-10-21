#pragma force_active on
typedef float f32;

struct Vec6 {
    f32 a, b, c, d, e, f;
};

extern "C" f32 lbl_80454DD8[8];

extern "C" void fn_800A4BA8(void* unused, const Vec6* src) {
    lbl_80454DD8[0] = src->a;
    lbl_80454DD8[1] = src->b;
    lbl_80454DD8[2] = src->c;
    lbl_80454DD8[3] = src->d;
    lbl_80454DD8[4] = src->e;
    lbl_80454DD8[5] = src->f;
}
