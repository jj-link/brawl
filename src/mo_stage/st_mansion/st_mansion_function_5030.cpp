#pragma force_active on
extern "C" int fn_47_5030(void *param)
{
    int val = *(int *)((char *)param + 8);
    return (val >> 19) & 1;
}
