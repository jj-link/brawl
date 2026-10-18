#pragma force_active on
extern "C" void fn_96_1E1D8(unsigned char *arg0)
{
    unsigned int tmp = *(const unsigned int *)(arg0 + 8);
    *(unsigned int *)(arg0 + 8) = tmp & ~(1 << 13);
}
