#pragma force_active on
typedef unsigned int u32;

extern "C" {
void *fn_27_1D53E4(u32 *base, u32 i, u32 j)
{
    u32 *p = *(u32 **)((char *)(base + i) + 0x58);
    return (void *)p[j];
}
}
