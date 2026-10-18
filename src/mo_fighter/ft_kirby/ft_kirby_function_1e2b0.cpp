#pragma force_active on
extern "C" int fn_96_1E2B0(void *obj)
{
    int v = *(int *)((char *)obj + 8);
    return (v >> 19) & 1;
}
