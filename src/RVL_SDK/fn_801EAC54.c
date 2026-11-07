#pragma force_active on
extern unsigned char lbl_8059EA4F;
extern unsigned char lbl_8059EA50;
extern unsigned char lbl_8059EA51;
extern unsigned char lbl_8059EA52;
void fn_801EA4E4(int, unsigned char *, int);
void fn_801EA098(int);

void fn_801EAC54(void) {
    unsigned char buf[5];
    buf[0] = 0x7a;
    buf[1] = lbl_8059EA4F & 0x7F;
    buf[2] = lbl_8059EA50 & 0x7F;
    buf[3] = lbl_8059EA51 & 0x7F;
    buf[4] = lbl_8059EA52 & 0x7F;
    fn_801EA4E4(0xe0, buf, 5);
    fn_801EA098(2);
}
