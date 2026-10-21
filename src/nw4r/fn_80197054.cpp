#pragma force_active on
extern "C" void *fn_80197054(void **arg0, unsigned int arg1)
{
    char *base = (char *)*arg0;
    unsigned short n = *(unsigned short *)(base + 0x38);
    char *p;

    if (n <= arg1)
        return 0;

    if (*(int *)(base + 0x14) != 0)
        p = base + *(int *)(base + 0x14);
    else
        p = 0;

    p = p + arg1 * 0x4C;
    if (*(unsigned int *)(p + 0xC) < n)
        return p;
    return 0;
}
