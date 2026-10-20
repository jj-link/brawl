#pragma force_active on
extern "C" int fn_48_BB24(void *p)
{
    unsigned int x = *(unsigned int *)((char *)p + 8);
    unsigned int r = (x << 12) | (x >> 20);
    return (int)(r & 0xFE000000) >> 26;
}
