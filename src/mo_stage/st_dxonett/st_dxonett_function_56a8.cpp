#pragma force_active on
typedef unsigned int u32;

extern "C" int fn_78_56A8(char *p)
{
    u32 v = *(u32 *)(p + 8);
    return (int)((v << 2) & 0xE0000000u) >> 30;
}
