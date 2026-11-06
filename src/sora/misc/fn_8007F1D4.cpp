#pragma force_active on
extern "C" int fn_8007D1AC(void);
extern "C" void fn_8007CB08(void);
extern "C" void fn_8007C9DC(void);
extern "C" void fn_8007C168(void);
extern int lbl_805A0214;
extern unsigned char lbl_805A024E;

extern "C" void setPause__13mvMoviePlayerFv(void) {
    if (lbl_805A0214 != 0) {
        int state = fn_8007D1AC();
        if (state == 2) {
            fn_8007CB08();
        }
        if (state == 5) {
            fn_8007C9DC();
            fn_8007C168();
            lbl_805A0214 = 0;
        }
    }
    lbl_805A024E = 1;
}