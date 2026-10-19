#pragma force_active on
class Obj {
public:
    int m;
};

extern "C" {
    extern signed char lbl_96_bss_FA8;
    extern Obj lbl_96_bss_FAC;
    extern char lbl_96_bss_E08[12];
    void fn_27_2DE170(Obj* p);
    void fn_27_2DE180(void* p, int n);
    void* __register_global_object(void* object, void* destructor, void* chain);

    Obj* fn_96_1FAAC() {
        if (lbl_96_bss_FA8 == 0) {
            fn_27_2DE170(&lbl_96_bss_FAC);
            __register_global_object(&lbl_96_bss_FAC, (void*)fn_27_2DE180, lbl_96_bss_E08);
            lbl_96_bss_FA8 = 1;
        }
        return &lbl_96_bss_FAC;
    }
}
