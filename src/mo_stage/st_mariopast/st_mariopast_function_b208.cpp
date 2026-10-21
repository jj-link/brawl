#pragma force_active on

extern "C" int fn_48_B208(void *p)
{
    int x = *(int *)((char *)p + 8);
    return ((x << 6) & (int)0xFE000000) >> 26;
}
