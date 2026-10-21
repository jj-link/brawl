#pragma force_active on
extern void fn_8022E928(const char* fmt, ...);
extern char lbl_8047E9F0[];
extern unsigned char lbl_804FB4A0[];

void fn_80229A78(int arg0) {
    fn_8022E928(lbl_8047E9F0, arg0, lbl_804FB4A0[0xd]);
    if (lbl_804FB4A0[0xd] != 0) {
        lbl_804FB4A0[0xd] = 8;
    }
}
