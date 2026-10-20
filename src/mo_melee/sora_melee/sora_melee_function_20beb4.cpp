#pragma force_active on
#pragma fp_contract off

extern const float lbl_27_rodata_2F90;
extern const float lbl_27_rodata_2FF4;

extern "C" float fn_27_20BEB4(const unsigned char* p, float t)
{
    float x;
    float c = lbl_27_rodata_2F90;
    x = c + t;
    float v = *(const float*)(p + 0x84) * t;
    float a = *(const float*)(p + 0x8C);
    float q = x * (a * x);
    float d = c * q - lbl_27_rodata_2FF4 * a;
    return *(const float*)(p + 0x60) + (v + d);
}
