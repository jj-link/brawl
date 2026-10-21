#pragma force_active on
extern "C" void *fn_801970A0(void **arg0, unsigned int arg1)
{
    unsigned char *obj = (unsigned char *)*arg0;
    unsigned short count = *(unsigned short *)(obj + 0x3A);
    if (count <= arg1)
        return 0;

    int off = *(int *)(obj + 0x18);
    unsigned char *base;
    if (off != 0)
        base = obj + off;
    else
        base = 0;

    unsigned char *entry = base + arg1 * 0x1C;
    if (*(unsigned int *)(entry + 0xC) < count)
        return entry;
    return 0;
}
