#pragma force_active on
extern "C" int fn_66_98C4(void *arg)
{
    unsigned int val = *(unsigned int *)((char *)arg + 8);
    return (val >> 25) & 1;
}
