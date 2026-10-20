#pragma force_active on
extern const float lbl_27_rodata_5EBC;

extern "C" unsigned long long fn_27_2B4D94(const float* p)
{
    union FloatBits {
        float f;
        unsigned int u;
    };

    FloatBits a;
    FloatBits b;
    a.f = p[2];
    b.f = lbl_27_rodata_5EBC;
    return ((unsigned long long)b.u << 32) | a.u;
}
