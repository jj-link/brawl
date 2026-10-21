#pragma force_active on
extern "C" void __dl__FPv(void*);
extern "C" extern int lbl_805A0460;

extern "C" void fn_801586C0(void) {
    if (lbl_805A0460 != 0) {
        if (lbl_805A0460 != 0) {
            __dl__FPv((void*)lbl_805A0460);
        }
        lbl_805A0460 = 0;
    }
}
