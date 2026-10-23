#pragma force_active on
extern char lbl_80529CF8[];
extern int fn_803F6150(const void *, const void *, unsigned long);

static inline char *find_entry(const void *arg0, unsigned long i)
{
    char *p = lbl_80529CF8 + 0x34;

    while (i < 4) {
        if (*(unsigned char *)(p + 0x119) != 0 &&
            fn_803F6150(p + 8, arg0, 6) == 0) {
            return p;
        }
        i++;
        p += 0x11C;
    }
    return 0;
}

unsigned short fn_80238E78(const void *arg0)
{
    unsigned long i = 0;
    char *p = find_entry(arg0, i);

    if (p != 0) {
        return *(unsigned short *)p;
    }
    return 0xFFFF;
}
