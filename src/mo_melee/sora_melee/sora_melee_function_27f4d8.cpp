#pragma force_active on
struct FnOut {
    void *ptr;
    int flag;
};

extern const float lbl_27_rodata_4614;
extern const float lbl_27_rodata_4610;

extern "C" {
void fn_27_27F4D8(FnOut *out, float *v, float f1, float f2, float f3)
{
    float one = lbl_27_rodata_4614;
    out->ptr = v;
    out->flag = 1;
    float zero = lbl_27_rodata_4610;
    v[0] = zero;
    v[1] = one + f3;
    v[2] = -f3 - one;
    v[3] = one + f1;
    v[4] = f2 - one;
}
}
