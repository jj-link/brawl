#pragma force_active on
extern char lbl_80529CF8[];
extern char lbl_804810DC[];
extern void fn_80231A74(int, void *, int, int, int, int, int, int);
extern int fn_803F6150(const void *, const void *, unsigned long);

void *fn_8023C7FC(unsigned char *arg0)
{
    unsigned int i;
    char *p = lbl_80529CF8 + 0x16E4;
    if ((unsigned char)lbl_80529CF8[0x27C0] >= 3) {
        fn_80231A74(0xD0002, lbl_804810DC, arg0[0], arg0[1], arg0[2], arg0[3], arg0[4], arg0[5]);
    }
    i = 0;
    do {
        if (*(unsigned char *)(p + 0x1A) != 0 && fn_803F6150(p + 0xA, arg0, 6) == 0) {
            return p + 8;
        }
        i++;
        p += 0x1C;
    } while (i < 12);
    return 0;
}