#pragma force_active on
extern "C" {
int fn_51_65D8(void *p)
{
    unsigned int w = *(unsigned int *)((char *)p + 8);
    return (int)(((w >> 25) & 7) << 29) >> 30;
}
}
