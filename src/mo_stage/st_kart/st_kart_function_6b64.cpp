#pragma force_active on
extern "C" int fn_49_6B64(void *p)
{
    int v = *(int *)((char *)p + 8);
    return (int)((((unsigned)v >> 27) & 7) << 29) >> 30;
}
