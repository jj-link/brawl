#pragma force_active on
extern "C" {
void* __register_global_object(void* object, void* dtor, void* chain);
void fn_27_197E44(void*);
void fn_27_197E54(void*);

extern signed char lbl_92_bss_1A4;
extern char lbl_92_bss_1A8[4];
extern char lbl_92_bss_18C[12];

void* fn_92_8B18() {
    if (lbl_92_bss_1A4 == 0) {
        fn_27_197E44(&lbl_92_bss_1A8);
        __register_global_object(&lbl_92_bss_1A8, (void*)fn_27_197E54, &lbl_92_bss_18C);
        lbl_92_bss_1A4 = 1;
    }
    return &lbl_92_bss_1A8;
}
}
