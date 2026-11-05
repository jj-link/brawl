#pragma force_active on
extern void fn_8022E928(const char* fmt, ...);
extern char lbl_8047E9CC[];
extern unsigned char lbl_804FB4A0[];

void fn_80229A00(int arg0) {
    fn_8022E928(lbl_8047E9CC, arg0, lbl_804FB4A0[0xc]);
    if (lbl_804FB4A0[0xc] != 0) {
        if (arg0 == 0) {
            lbl_804FB4A0[0xc] = 0x17;
        } else {
            lbl_804FB4A0[0xc] = 0xFF;
        }
    }
}
