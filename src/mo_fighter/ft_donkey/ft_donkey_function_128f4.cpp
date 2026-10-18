#pragma force_active on
struct __attribute__((packed)) S0 { float v[4]; };

extern "C" extern const float lbl_92_rodata_A8;

extern "C" void fn_92_128F4(S0* object)
{
     const float* p = (&lbl_92_rodata_A8 + 1) - 1;
    object->v[3] = *p;
    object->v[2] = *p;
}
