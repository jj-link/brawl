#pragma force_active on
extern "C" {
int fn_62_A528(void *p)
{
    unsigned int x = *(unsigned int *)((char *)p + 8);
    return (int)(((x >> 27) & 7) << 29) >> 30;
}
}
