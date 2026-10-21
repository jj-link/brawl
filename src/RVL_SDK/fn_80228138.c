#pragma force_active on
extern unsigned char lbl_804F9FC0[0x14A0];

void fn_80228138(int arg0) {
    unsigned char *p = (unsigned char *)lbl_804F9FC0 + arg0 * 0x528;
    p[0x520] = 0;
}
