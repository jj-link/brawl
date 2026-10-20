#pragma force_active on
typedef unsigned int u32;

extern "C" {
int fn_48_B708(void *p)
{
    u32 x = *(u32 *)((char *)p + 8);
    int v = (int)((x << 7) & 0xFF000000);
    return v >> 25;
}
}
