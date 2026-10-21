#pragma force_active on
extern char lbl_804E7AE0[];
extern unsigned short lbl_805A0A78;
extern unsigned short lbl_805A0A7A;
extern unsigned short lbl_805A0A7C;
extern unsigned short lbl_805A0A7E;
extern int lbl_805A0A80;
extern int lbl_805A0A88;
extern char *lbl_805A0A8C;
extern int lbl_805A0A90;

void fn_80200988(void) {
    unsigned int base = 0x10000;
    lbl_805A0A88 = 0;
    lbl_805A0A90 = 0;
    lbl_805A0A8C = lbl_804E7AE0;
    lbl_805A0A80 = 1;
    lbl_805A0A7E = base - 0x8000;
    lbl_805A0A7C = base - 0x8000;
    lbl_805A0A7A = base - 0x8000;
    lbl_805A0A78 = base - 0x8000;
}
