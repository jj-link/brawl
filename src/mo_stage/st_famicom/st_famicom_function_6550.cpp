#pragma force_active on
extern "C" {
int fn_68_6550(void *p)
{
    unsigned int x = *(unsigned int *)((char *)p + 8);
    return (int)((x >> 23 & 0x1F) << 27) >> 28;
}
}
