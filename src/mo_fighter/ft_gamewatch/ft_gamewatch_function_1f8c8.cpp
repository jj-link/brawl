#pragma force_active on
extern "C" const float lbl_107_rodata_138;

extern "C" void fn_107_1F8C8(void *a, void *b, float *out)
{
    const float *p = &lbl_107_rodata_138;
    out[2] = p[10];
    out[3] = p[11];
    out[0] = p[12];
}
