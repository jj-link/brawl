#pragma force_active on
extern "C" {

extern signed char lbl_116_bss_154;
extern void* lbl_116_bss_158;
extern void* lbl_116_bss_140[];
extern void fn_27_368C08(void*);
extern void* fn_27_368C18(void*, int);
extern void* __register_global_object(void*, void*, void*);

void* fn_116_972C() {
    if (!lbl_116_bss_154) {
        fn_27_368C08(&lbl_116_bss_158);
        __register_global_object(&lbl_116_bss_158, (void*)fn_27_368C18, lbl_116_bss_140);
        lbl_116_bss_154 = 1;
    }
    return &lbl_116_bss_158;
}

}
