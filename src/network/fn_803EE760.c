#pragma force_active on
extern int lbl_80599680[];
extern char lbl_804931C0[];
extern int fn_803CB314(int, int *);
extern int fn_803EED98(void *, void *);
extern void OSReport(const char *, ...);

int fn_803EE760(int a, int *b)
{
    char *s = lbl_804931C0;
    int sp8;
    int e;
    int r;
    if (a == 0 || b == 0) return 1;
    if (!(lbl_80599680[0] & 2)) return 15;
    if (lbl_80599680[5] != 0) return 15;
    if (lbl_80599680[4] == 0) return 6;
    e = fn_803CB314(lbl_80599680[2], &sp8);
    if (e != 0) {
        OSReport(s + 0x130, e);
        return 0x15;
    }
    if (!(sp8 & 1)) {
        OSReport(s + 0x318);
        return 6;
    }
    if (sp8 & 2) {
        OSReport(s + 0x350);
        return 6;
    }
    if (!(sp8 & 0x10000)) {
        OSReport(s + 0x384);
        return 0x15;
    }
    b[3] = 4;
    if (sp8 & 4) b[3] |= 1;
    r = fn_803EED98(b, b + 2);
    if (r != 0) {
        OSReport(s + 0x3C4);
        return r;
    }
    *(short *)((char *)b + 4) = 0;
    *((char *)b + 6) = 0;
    *((char *)b + 7) = 0;
    b[4] = 0;
    return 0;
}
