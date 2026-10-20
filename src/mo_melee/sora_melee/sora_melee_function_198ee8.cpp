#pragma force_active on
extern "C" int fn_27_198EE8(unsigned int *p)
{
    unsigned int x = p[2];
    return (int)((x << 4 | x >> 28) & 0xE0000000u) >> 30;
}
