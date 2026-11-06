#pragma force_active on
extern int fn_803EC6E8(void);
extern void *fn_803D634C(void *, int, unsigned int);
extern int fn_803ECB5C(unsigned char *, unsigned char *, int *, int);
extern int fn_803EC8F0(void *, int *);
extern int fn_8020AB58(void *, const void *, unsigned int);
extern int fn_8020BC3C(void *);
extern int fn_8020A870(void *);
extern void fn_803ECA2C(void *);

int fn_803EC51C(unsigned char *p)
{
    unsigned char c[0x200] __attribute__((aligned(32)));
    unsigned char b[0x200] __attribute__((aligned(32)));
    unsigned char a[0x200] __attribute__((aligned(32)));
    int type;
    int sectors;
    int result;
    unsigned int remaining;

    result = fn_803EC6E8();
    if (result != 0)
        return result;
    fn_803D634C(b, 0, 0x200);
    sectors = 0;
    fn_803ECB5C(p, b, &type, 0);
    if (type != fn_803EC8F0(b, &sectors))
        fn_803ECB5C(p, b, &type, sectors);
    result = fn_8020AB58(p + 0x58, b, 0x200);
    if (result < 0) {
        fn_8020BC3C(p + 0x58);
        fn_8020A870(p + 4);
        return result;
    }
    remaining = *(unsigned int *)(p + 0x54) - 0x200;
    if (type == 2) {
        fn_803ECA2C(a);
        result = fn_8020AB58(p + 0x58, a, 0x200);
        if (result < 0) {
            fn_8020BC3C(p + 0x58);
            fn_8020A870(p + 4);
            return result;
        }
        remaining -= 0x200;
    }
    fn_803D634C(c, 0, 0x200);
    while (remaining >= 0x200) {
        result = fn_8020AB58(p + 0x58, c, 0x200);
        if (result < 0) {
            fn_8020BC3C(p + 0x58);
            fn_8020A870(p + 4);
            return result;
        }
        remaining -= 0x200;
    }
    if (remaining != 0) {
        result = fn_8020AB58(p + 0x58, c, remaining);
        if (result < 0) {
            fn_8020BC3C(p + 0x58);
            fn_8020A870(p + 4);
            return result;
        }
    }
    return 0;
}