#pragma force_active on
extern unsigned char lbl_8059EA4B;
extern unsigned char lbl_8059EA4C;
extern unsigned char lbl_8059EA4D;
extern unsigned char lbl_8059EA4E;
void fn_801EA4E4(int, unsigned char *, int);
void fn_801EA098(int);

void fn_801EABF0(void) {
    unsigned char buf[8];
    unsigned char a = lbl_8059EA4B;
    unsigned char b = lbl_8059EA4D;
    unsigned char c = lbl_8059EA4C;
    unsigned char d = lbl_8059EA4E;
    buf[0] = 8;
    buf[1] = ((c << 4) & 0xF0) | (a & 0xF);
    buf[2] = ((d << 3) & 0x38) | (b & 7);
    fn_801EA4E4(0xE0, buf, 3);
    fn_801EA098(2);
}