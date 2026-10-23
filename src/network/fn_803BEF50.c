#pragma force_active on
extern char lbl_8053B248[];
extern void fn_803A9938(unsigned int, short *, short *);

int fn_803BEF50(short *out, int str)
{
    short spA;
    short sp8;
    int off;
    int count;

    count = 0;
    off = 0;
    while ((signed char)((char *)str)[off] != 0) {
        unsigned int r = (*(unsigned int (**)(int, short *))
                         (lbl_8053B248 + 0x24))(str + off, out);
        fn_803A9938(r, &spA, &sp8);
        count++;
        out = (short *)((char *)out + (sp8 & 0xFFFFFFFE));
        off += spA;
    }
    *out = 0;
    return count;
}
