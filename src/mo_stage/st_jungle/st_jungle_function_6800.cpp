#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_51_6800(void *p)
{
    u32 w = *(u32 *)((char *)p + 8);
    return (int)((w << 8) & 0xF8000000) >> 28;
}
}
