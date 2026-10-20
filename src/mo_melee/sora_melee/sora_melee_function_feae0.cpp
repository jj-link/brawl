#pragma force_active on
typedef unsigned int u32;

extern "C" int fn_27_FEAE0(const u32 *p)
{
    return (int)((p[2] << 2) & 0xE0000000u) >> 30;
}
