#pragma force_active on
typedef unsigned int u32;

extern "C" int fn_47_4CBC(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    int r = (int)(((x << 4) | (x >> 28)) & 0xE0000000u);
    return r >> 30;
}
