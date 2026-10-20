#pragma force_active on
extern "C" int fn_48_B7D0(void *p)
{
    unsigned int x = *(unsigned int *)((char *)p + 8);
    unsigned int r = (x << 7) | (x >> 25);
    return (int)(r & 0xFF000000) >> 25;
}
