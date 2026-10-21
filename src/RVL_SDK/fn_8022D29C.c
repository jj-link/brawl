#pragma force_active on
extern int lbl_805A0CE0;
extern char lbl_804FB4A0[];
extern char lbl_8047F0D4[];
extern void fn_8022E928(const char* fmt, ...);

void fn_8022D29C(int a) {
    char* p = lbl_804FB4A0;
    if (a == 0) {
        lbl_805A0CE0 = 0;
        p[0x708] = 0;
    } else {
        fn_8022E928(lbl_8047F0D4);
    }
}
