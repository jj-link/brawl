#pragma force_active on
extern "C" {
extern signed char lbl_109_bss_130;
extern char lbl_109_bss_134[4];
extern char lbl_109_bss_124[12];
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
void __register_global_object(void*, void*, void*);
}

extern "C" void* fn_109_8454() {
    if (lbl_109_bss_130 == 0) {
        fn_27_197E44(lbl_109_bss_134);
        __register_global_object(lbl_109_bss_134, (void*)fn_27_197E54, lbl_109_bss_124);
        lbl_109_bss_130 = 1;
    }
    return lbl_109_bss_134;
}
