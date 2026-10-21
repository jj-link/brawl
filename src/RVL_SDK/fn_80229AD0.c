#pragma force_active on
void fn_8022E928(const char* fmt, ...);
extern char lbl_8047EA18[];
extern unsigned char lbl_804FB4A0[];

void fn_80229AD0(int arg0) {
    fn_8022E928(lbl_8047EA18, arg0, lbl_804FB4A0[0x11]);
    lbl_804FB4A0[0x11] = 3;
}
