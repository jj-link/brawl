#pragma force_active on
extern "C" {
extern int fn_8015E680(void*, int);
extern char lbl_80497E1C[];
extern signed char lbl_805A0192;
extern int lbl_805A0184;

int fn_8006C6A0(int arg0) {
    int result = fn_8015E680(lbl_80497E1C, arg0);
    lbl_805A0192 = 1;
    lbl_805A0184 = 0;
    return result;
}
}
