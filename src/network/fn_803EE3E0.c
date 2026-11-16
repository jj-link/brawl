#pragma force_active on
extern int lbl_80599680[];
extern char lbl_804931C0[];
extern int fn_803CB83C(int);
extern int fn_803CC360(int, int, void *, int);
extern void fn_803D634C(void *, int, unsigned int);
extern void OSReport(const char *, ...);

int fn_803EE3E0(int a)
{
    char *s;
    unsigned int count;
    int r;
    int spC;
    int sp10[4];
    short sp8;

    s = lbl_804931C0;
    if (a == 0) return 1;
    lbl_80599680[5] = 0;
    if (lbl_80599680[4 + lbl_80599680[5]] == 0) return 6;
    if (lbl_80599680[0] & 2) {
        OSReport(s + 0x1A4);
        return 0;
    }
    count = 0;
    for (;;) {
        if (lbl_80599680[4] == 0) return 6;
        r = fn_803CB83C(lbl_80599680[2]);
        if (r == 0) break;
        OSReport(s + 0x1D4, r);
        count++;
        if (count >= 5) break;
    }
    if (count == 5) return 0x15;
    if (lbl_80599680[5] != 0) return 6;
    spC = 0;
    if (fn_803CC360(lbl_80599680[2], 0x29, &spC, 4) != 0) {
        OSReport(s + 0x214);
        return 0x15;
    }
    fn_803D634C(sp10, 0, 0x10);
    if (fn_803CC360(lbl_80599680[2], 0xA, sp10, 0x10) != 0) {
        OSReport(s + 0x244);
        return 0x15;
    }
    sp8 = 0;
    if (fn_803CC360(lbl_80599680[2], 3, &sp8, 2) != 0) {
        OSReport(s + 0x274);
        return 0x15;
    }
    lbl_80599680[0] |= 2;
    return 0;
}
