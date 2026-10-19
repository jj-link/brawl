#pragma force_active on
extern "C" {
extern signed char lbl_103_bss_1A4;
extern unsigned int lbl_103_bss_1A8;
extern unsigned char lbl_103_bss_18C[12];

void fn_27_197E44(void* self);
void* fn_27_197E54(void* p, int n);
void __register_global_object(void* object, void* destructor, void* handle);

void* fn_103_8F34(void) {
    if (lbl_103_bss_1A4 == 0) {
        fn_27_197E44(&lbl_103_bss_1A8);
        __register_global_object(&lbl_103_bss_1A8, (void*)fn_27_197E54, lbl_103_bss_18C);
        lbl_103_bss_1A4 = 1;
    }
    return &lbl_103_bss_1A8;
}
}
