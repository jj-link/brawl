#include <types.h>

#pragma force_active on

extern "C" void fn_802878F0(f32 *out, void *m, f32 *v);
extern "C" f32 lbl_805A4138;

extern "C" void fn_802D5734(f32 *bounds, void *m, const f32 *a, const f32 *b) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    f32 temp_f4;
    f32 v[4] __attribute__((aligned(16)));
    f32 out[4] __attribute__((aligned(16)));

    temp_f4 = a[2] * b[2];
    temp_f3 = a[1] * b[1];
    temp_f1 = a[0] * b[0];
    v[2] = temp_f4;
    v[1] = temp_f3;
    v[0] = temp_f1;
    v[3] = lbl_805A4138;

    fn_802878F0(out, m, v);

    bounds[0] = (bounds[0] < out[0]) ? bounds[0] : out[0];
    bounds[1] = (bounds[1] < out[1]) ? bounds[1] : out[1];
    bounds[2] = (bounds[2] < out[2]) ? bounds[2] : out[2];
    bounds[3] = (bounds[3] < out[3]) ? bounds[3] : out[3];
    bounds[4] = (bounds[4] > out[0]) ? bounds[4] : out[0];
    bounds[5] = (bounds[5] > out[1]) ? bounds[5] : out[1];
    bounds[6] = (bounds[6] > out[2]) ? bounds[6] : out[2];
    bounds[7] = (bounds[7] > out[3]) ? bounds[7] : out[3];
}