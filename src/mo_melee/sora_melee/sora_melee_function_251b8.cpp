#pragma force_active on
extern "C" int fn_27_251B8(const float *p)
{
    extern const float lbl_27_rodata_388[];

    float value = p[0x40 / sizeof(float)];
    float reference = lbl_27_rodata_388[1];
    float threshold;

    if (reference == value)
        threshold = lbl_27_rodata_388[2];
    else
        threshold = lbl_27_rodata_388[8];

    return p[0x60 / sizeof(float)] != threshold;
}
