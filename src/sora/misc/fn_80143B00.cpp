#pragma force_active on
extern "C" {
    extern void __dl__FPv(void*);
    extern int lbl_805A03A8;

    void* fn_80143B00(void* arg0, int arg1) {
        if (arg0 != 0) {
            lbl_805A03A8 = 0;
            if (arg1 > 0) {
                __dl__FPv(arg0);
            }
        }
        return arg0;
    }
}
