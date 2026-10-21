#pragma force_active on
extern "C" {
extern char lbl_80497E44[];
void fn_8015E680(void* a, int b);
}
extern int lbl_805A0188;

extern "C" void fn_8006C75C(int arg0) {
    fn_8015E680(lbl_80497E44, arg0);
    lbl_805A0188 = 0;
}
