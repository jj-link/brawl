#pragma force_active on
extern "C" int fn_48_B994(void *p)
{
    int v = *(int *)((char *)p + 8);
    int t = (v << 14) & 0xFF000000;
    return t >> 25;
}
