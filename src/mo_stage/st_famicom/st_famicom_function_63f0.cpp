#pragma force_active on
extern "C" int fn_68_63F0(int *p)
{
    unsigned int x = (unsigned int)p[2];
    return (int)((x << 2) & 0xE0000000u) >> 30;
}
