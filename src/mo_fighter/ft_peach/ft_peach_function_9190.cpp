#pragma force_active on
extern "C" {
void fn_27_3312B0(void*);
void fn_27_3312C0(void*, int);
void* __register_global_object(void*, void*, void*);

extern signed char lbl_103_bss_1AC;
extern void* lbl_103_bss_1B0;
extern void* lbl_103_bss_198;
}

extern "C" void* fn_103_9190() {
    if (lbl_103_bss_1AC == 0) {
        fn_27_3312B0(&lbl_103_bss_1B0);
        __register_global_object(&lbl_103_bss_1B0, (void*)fn_27_3312C0, &lbl_103_bss_198);
        lbl_103_bss_1AC = 1;
    }
    return &lbl_103_bss_1B0;
}
