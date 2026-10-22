#pragma force_active on
typedef float f32;
extern f32 lbl_805A43E0;
extern f32 lbl_805A43F4;
struct Q { f32 x, y, z, w; };
extern "C" void fn_802E6F40(Q* __restrict out, const Q* __restrict in) {
    f32 one = lbl_805A43F4;
    out->x = one / in->x;
    out->y = one / in->y;
    out->z = one / in->z;
    if (lbl_805A43E0 != in->w) {
        out->w = one / in->w;
    } else {
        out->w = one;
    }
}
