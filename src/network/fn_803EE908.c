#pragma force_active on
extern int lbl_80599680[];
extern unsigned char fn_803EEEB4(int, unsigned char *, int);
extern void fn_803D80C4(unsigned int *);

int fn_803EE908(void) {
    unsigned char sp8;

    if (lbl_80599680[0] & 1) {
        if ((char)((char *)lbl_80599680)[0x18] == 0) {
            if (fn_803EEEB4(lbl_80599680[3], &sp8, 1) == 1) {
                ((char *)lbl_80599680)[0x18] = sp8;
            }
        }
        if (lbl_80599680[4] != 0) {
            fn_803D80C4((unsigned int *)lbl_80599680[3]);
            return 1;
        }
        return 0;
    }
    return 0;
}
