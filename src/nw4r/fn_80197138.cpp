#pragma force_active on
extern "C" void *fn_80197138(void **arg0, unsigned int arg1)
{
    unsigned char *base = (unsigned char *)*arg0;
    unsigned short n = *(unsigned short *)(base + 0x3E);
    unsigned char *p;

    if (n <= arg1)
        return 0;

    if (*(int *)(base + 0x20) != 0)
        p = base + *(int *)(base + 0x20);
    else
        p = 0;

    p = p + arg1 * 0x28;
    if (*(unsigned int *)(p + 0xC) < n)
        return p;
    return 0;
}
