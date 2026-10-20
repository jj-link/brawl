#pragma force_active on
extern "C" int fn_52_7634(void *p)
{
    int v = *(int *)((char *)p + 8);
    return ((v << 4) & (int)0xF8000000) >> 28;
}
