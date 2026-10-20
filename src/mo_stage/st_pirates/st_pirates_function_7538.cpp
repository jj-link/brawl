#pragma force_active on
extern "C" int fn_52_7538(void *p)
{
    unsigned int x = ((unsigned int *)p)[2];
    return (int)(((x >> 25) & 7u) << 29) >> 30;
}
