#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_78_57A4(char *p)
{
    u32 v = *(u32 *)(p + 8);
    int r = (int)((v << 4) & 0xE0000000u);
    return r >> 30;
}
}
