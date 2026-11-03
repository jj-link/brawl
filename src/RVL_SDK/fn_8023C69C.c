#pragma force_active on
extern void fn_80231A74(int, void *, int, int, int, int, int, int);
extern int fn_803F6150(void *, void *, unsigned long);
extern void fn_8023D57C(void *, void *, int, int, int);
extern unsigned char lbl_80529CF8[];
extern unsigned char lbl_8048107C[];

void fn_8023C69C(unsigned char *arg0, int arg1)
{
    unsigned char *entry;
    unsigned char *found;
    unsigned int i;
    unsigned char *dst;

    dst = 0;
    if (lbl_80529CF8[0x27C0] >= 3) {
        fn_80231A74(0xD0002, lbl_8048107C, arg0[0], arg0[1], arg0[2], arg0[3], arg0[4], arg0[5]);
    }

    i = 0;
    entry = lbl_80529CF8 + 0x16E4;
    for (;;) {
        if (entry[0x1A] != 0 && fn_803F6150(entry + 0xA, arg0, 6) == 0) {
            found = entry;
            break;
        }
        i++;
        entry += 0x1C;
        if (i >= 12) {
            found = 0;
            break;
        }
    }

    if (found != 0) {
        dst = found + 8;
    }
    fn_8023D57C(arg0, dst, 1, 0x28, arg1);
}
