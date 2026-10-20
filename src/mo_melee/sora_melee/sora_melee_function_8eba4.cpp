#pragma force_active on
extern "C" const unsigned char lbl_27_rodata_C30[];

extern "C" float fn_27_8EBA4(float value) {
    const float* p = reinterpret_cast<const float*>(lbl_27_rodata_C30);
    float x = p[2] * value;

    for (;;) {
        if (x > p[0]) {
            x -= p[0];
        } else if (x < p[1]) {
            x += p[0];
        } else {
            break;
        }
    }

    return p[3] * x;
}
