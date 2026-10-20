#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_79_5B3C(void *p)
{
    u32 v = *(u32 *)((char *)p + 8);
    int r = (int)((v << 4) & 0xE0000000);
    return r >> 30;
}
}
