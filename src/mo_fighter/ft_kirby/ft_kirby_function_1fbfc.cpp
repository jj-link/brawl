#pragma force_active on
struct DestructorChain {
    struct DestructorChain *next;
    void *destructor;
    void *object;
};

extern "C" {
extern char lbl_96_bss_FC0;
extern int lbl_96_bss_FC4;
extern DestructorChain lbl_96_bss_E2C;
void fn_27_3076D8(void* p);
void* fn_27_3076E8(void* p, int n);
void* __register_global_object(void* object, void* destructor, DestructorChain* chain);
}

extern "C" int* fn_96_1FBFC() {
    if (lbl_96_bss_FC0 == 0) {
        fn_27_3076D8(&lbl_96_bss_FC4);
        __register_global_object(&lbl_96_bss_FC4, (void*)fn_27_3076E8, &lbl_96_bss_E2C);
        lbl_96_bss_FC0 = 1;
    }
    return &lbl_96_bss_FC4;
}
