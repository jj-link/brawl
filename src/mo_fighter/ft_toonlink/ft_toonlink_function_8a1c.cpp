#pragma force_active on
extern "C" {
extern signed char lbl_121_bss_12C;
extern int lbl_121_bss_130;
extern char lbl_121_bss_114[12];
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
void __register_global_object(void*, void*, void*);
}

extern "C" int* fn_121_8A1C() {
    if (lbl_121_bss_12C == 0) {
        fn_27_197E44(&lbl_121_bss_130);
        __register_global_object(&lbl_121_bss_130, (void*)fn_27_197E54, lbl_121_bss_114);
        lbl_121_bss_12C = 1;
    }
    return &lbl_121_bss_130;
}
