#pragma force_active on
extern char lbl_80529CF8[];
extern char lbl_80480AD8[];
extern void fn_80231A74(int, void *, int, int, int, int, int, int);
extern int fn_803F6150(const void *, const void *, unsigned long);

static inline char *find_entry(const void *arg0)
{
    char *p;
    unsigned long i;
    i = 0;
    p = lbl_80529CF8 + 0x34;
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

int fn_80238D34(unsigned char *arg0)
{
    char *p;
    if ((unsigned char)lbl_80529CF8[0x27C0] >= 3) {
        fn_80231A74(0xD0002, lbl_80480AD8, arg0[0], arg0[1], arg0[2], arg0[3], arg0[4], arg0[5]);
    }
    p = find_entry(arg0);
    if (p != 0) {
        return 1;
    }
    return 0;
}