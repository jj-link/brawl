#pragma force_active on
extern "C" {
extern int lbl_80497DF4[];
extern int lbl_805A0180;
extern bool lbl_805A0191;

int fn_8015E680(void* a, int b);

int fn_8006C620(int arg0) {
    int result = fn_8015E680(lbl_80497DF4, arg0);
    lbl_805A0191 = true;
    lbl_805A0180 = 0;
    return result;
}
}
