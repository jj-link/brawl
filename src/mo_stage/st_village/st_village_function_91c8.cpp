#pragma force_active on
extern "C" {
int fn_70_91C8(char *p)
{
    int v = *(int *)(p + 0x8);
    return (int)(((unsigned)v << 2) & 0xE0000000) >> 30;
}
}
