#pragma force_active on
extern "C" {
int fn_49_6D28(unsigned char *p)
{
    unsigned int x = *(unsigned int *)(p + 8);
    return (int)(((x >> 25) & 7) << 29) >> 30;
}
}
