#pragma force_active on
extern char lbl_804FB4A0[];
extern char lbl_8047FA70[];
extern void fn_8022E928(const char* fmt, ...);

void fn_8022E8C4(int a, int b, int c, int d, int e, unsigned int f) {
    char* base = lbl_804FB4A0;
    if (f == 3) {
        void (*fp)(int, int, int) = *(void (**)(int, int, int))(base + 0x6ec);
        if (fp != 0) {
            fp(a, b, c);
        }
    } else {
        fn_8022E928(lbl_8047FA70, f);
    }
}
