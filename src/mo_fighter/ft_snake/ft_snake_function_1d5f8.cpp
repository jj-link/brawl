#pragma force_active on
extern "C" void fn_122_1D5F8(unsigned char *self, int unused, float *out)
{
    unsigned char *p = *(unsigned char **)(self + 0x221c);
    *out = *out + *(float *)(p + 0x34);
}
