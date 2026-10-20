#pragma force_active on
extern "C" int fn_54_674C(const int *p)
{
    unsigned int v = (unsigned int)p[2];
    return (int)((v << 2) & 0xE0000000u) >> 30;
}
