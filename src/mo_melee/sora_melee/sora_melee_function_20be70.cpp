#pragma force_active on
extern "C" {
extern const float lbl_27_rodata_2F90;
extern const float lbl_27_rodata_2FF4;
}

#pragma fp_contract off

extern "C" float fn_27_20BE70(const unsigned char* p, float t)
{
    float v = *(const float*)(p + 0x80) * t;
    float g = *(const float*)(p + 0x88);

    return *(const float*)(p + 0x5C) +
        (v + (lbl_27_rodata_2F90 *
            ((lbl_27_rodata_2F90 + t) *
             (g * (lbl_27_rodata_2F90 + t))) -
            lbl_27_rodata_2FF4 * g));
}
