#pragma force_active on
static inline unsigned int test(char *p)
{
    switch (*(int *)(p + 0x3c)) {
    case 1:
        if (*(unsigned int *)(p + 0xc) & 0x800000)
            return 0;
        break;
    default:
        break;
    }
    return (*(unsigned int *)(p + 0xc) >> 12) & 1;
}
extern "C" int fn_24_2FC8(void *arg0)
{
    char *p = (char *)arg0;
    for (int i = 0; i < 4; i++) {
        if (test(p) == 1) return 1;
        if (test(p + 0x100) == 1) return 1;
        p += 0x40;
    }
    return 0;
}