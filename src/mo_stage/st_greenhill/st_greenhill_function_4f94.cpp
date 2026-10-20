#pragma force_active on
extern "C" int fn_72_4F94(void *arg)
{
    unsigned int v = *(unsigned int *)((char *)arg + 8);
    return (v >> 25) & 1;
}
