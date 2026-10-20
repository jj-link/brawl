#pragma force_active on
extern "C" int fn_48_BBEC(void *p)
{
    unsigned int x = *(unsigned int *)((char *)p + 8);
    unsigned int r = ((x >> 20) | (x << 12)) & 0xFE000000u;
    return ((int)r) >> 26;
}
