#pragma force_active on
extern void fn_8022E928(const char* fmt, ...);
extern char lbl_8047EA40[];
extern unsigned char lbl_804FB4A0[];

void fn_80229B1C(int arg0) {
    fn_8022E928(lbl_8047EA40, arg0, lbl_804FB4A0[0x10]);
    lbl_804FB4A0[0x10] = 4;
}
