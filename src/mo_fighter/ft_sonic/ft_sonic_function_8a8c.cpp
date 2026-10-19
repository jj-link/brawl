#pragma force_active on
extern "C" {
void fn_27_197E44(void*);
void fn_27_197E54(void*, int);
void* __register_global_object(void*, void*, void*);
extern signed char lbl_123_bss_2E4;
extern int lbl_123_bss_2E8;
extern char lbl_123_bss_2CC[];

void* fn_123_8A8C() {
    if (!lbl_123_bss_2E4) {
        fn_27_197E44(&lbl_123_bss_2E8);
        __register_global_object(&lbl_123_bss_2E8, (void*)fn_27_197E54, lbl_123_bss_2CC);
        lbl_123_bss_2E4 = 1;
    }
    return &lbl_123_bss_2E8;
}
}
