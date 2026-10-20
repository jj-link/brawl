#pragma force_active on
extern "C" int fn_68_638C(unsigned int *p)
{
    unsigned int v = p[2];
    return (int)(((v << 4) | (v >> 28)) & 0xE0000000) >> 30;
}
