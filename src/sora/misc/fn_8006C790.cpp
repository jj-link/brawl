#pragma force_active on
extern "C" void fn_8015E7C4(void*);
extern "C" void free__13gfHeapManagerFPv(void*);
extern char lbl_80497E44[];
extern int lbl_805A0188;

extern "C" int fn_8006C790(void) {
    fn_8015E7C4(lbl_80497E44);
    if (lbl_805A0188 != 0) {
        free__13gfHeapManagerFPv((void*)lbl_805A0188);
        lbl_805A0188 = 0;
    }
    return 1;
}
