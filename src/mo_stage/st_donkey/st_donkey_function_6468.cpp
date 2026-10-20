#pragma force_active on
extern "C" int fn_50_6468(void *p)
{
    unsigned int x = *(unsigned int *)((char *)p + 8);
    unsigned int r = (x << 8) | (x >> 24);
    return (int)(r & 0xF8000000u) >> 28;
}
