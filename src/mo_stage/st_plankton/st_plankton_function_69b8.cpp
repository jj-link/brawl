#pragma force_active on

extern "C" int fn_74_69B8(int *p)
{
    return (int)((*(unsigned int *)((char *)p + 8) << 4) & 0xE0000000u) >> 30;
}
