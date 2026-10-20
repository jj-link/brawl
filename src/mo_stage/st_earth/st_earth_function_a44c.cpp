#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_66_A44C(void *p)
{
    return (int)(((u32)(((u32 *)p)[2] << 4)) & 0xE0000000u) >> 30;
}
}
