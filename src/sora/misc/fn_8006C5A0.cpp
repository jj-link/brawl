#pragma force_active on

extern "C" {
extern char lbl_80497DCC[];
extern int lbl_805A017C;
extern signed char lbl_805A0190;

int fn_8015E680(void* a, int b);

int fn_8006C5A0(int arg0) {
    int result = fn_8015E680(lbl_80497DCC, arg0);
    lbl_805A0190 = 1;
    lbl_805A017C = 0;
    return result;
}
}
