#pragma force_active on
extern unsigned char lbl_8059EA48;
extern unsigned char lbl_8059EA49;
extern unsigned char lbl_8059EA4A;
void fn_801EA4E4(int, void*, int);
void fn_801EA098(int);

void fn_801EAB98(void) {
    unsigned char buf[8];
    unsigned char a = lbl_8059EA48;
    unsigned char b = lbl_8059EA4A;
    unsigned char c = lbl_8059EA49;
    buf[0] = 5;
    buf[1] = ((c << 2) & 0x3C) | (a & 3);
    buf[2] = b;
    fn_801EA4E4(0xe0, buf, 3);
    fn_801EA098(2);
}
