#pragma force_active on
extern char lbl_805644C0[];
extern void fn_803D65A4(unsigned int value, short *hi, short *lo);

int fn_803E7D7C(short *arg0, char *arg1)
{
    int offset;
    int count;
    short spA;
    short sp8;
    unsigned int value;

    count = 0;
    offset = 0;
    while (*(signed char *)(arg1 + offset) != 0) {
        value = ((unsigned int (*)(char *, short *))
            (*(int *)(lbl_805644C0 + 0x48)))(
                (char *)((unsigned int)arg1 + offset), arg0);
        fn_803D65A4(value, &spA, &sp8);
        count += 1;
        arg0 = (short *)((char *)arg0 + (sp8 & ~1));
        offset += spA;
    }
    *arg0 = 0;
    return count;
}
