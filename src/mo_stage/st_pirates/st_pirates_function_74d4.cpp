#pragma force_active on
extern "C" int fn_52_74D4(unsigned int *p)
{
    int v = (int)(p[2] << 2) & (int)0xE0000000;
    return v >> 30;
}
