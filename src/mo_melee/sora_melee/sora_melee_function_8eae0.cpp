#pragma force_active on

extern "C" const float lbl_27_rodata_C30;
extern "C" const float lbl_27_rodata_C34;

inline float wrap(float x) {
    for (;;) {
        if (x > lbl_27_rodata_C30) {
            x -= lbl_27_rodata_C30;
        } else if (x < lbl_27_rodata_C34) {
            x += lbl_27_rodata_C30;
        } else {
            break;
        }
    }
    return x;
}

extern "C" void fn_27_8EAE0(float* out, const float* in) {
    float x = wrap(in[0]);
    float y = wrap(in[1]);
    float z = in[2];
    in = 0;
    z = wrap(z);

    out[0] = x;
    out[1] = y;
    out[2] = z;
}
