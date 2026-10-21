#pragma force_active on

extern "C" void fn_801357F0(float* dst, const float* a, const float* b, float c)
{
    float t;
    float b0;
    float a1;
    float a0;

    t = b[1];
    a0 = a[0];
    a1 = a[1];
    b0 = b[0];

    dst[15] = a0;
    dst[16] = a1;
    dst[17] = b0;
    dst[18] = t;
    dst[19] = c;
    dst[20] = t;
}
