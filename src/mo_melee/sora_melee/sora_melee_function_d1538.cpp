#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_27_D1538(int *p)
{
    return (int)(((u32)p[2] << 10) & 0xFC000000) >> 27;
}
}
