#pragma force_active on
extern "C" {
extern signed char lbl_97_bss_1BC;
extern unsigned char lbl_97_bss_1C0[4];
extern unsigned char lbl_97_bss_1A4[12];
void fn_27_197E44(void*);
void fn_27_197E54(void*, short);
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_97_9F28() {
    if (!lbl_97_bss_1BC) {
        fn_27_197E44(lbl_97_bss_1C0);
        __register_global_object(lbl_97_bss_1C0, (void*)fn_27_197E54, lbl_97_bss_1A4);
        lbl_97_bss_1BC = 1;
    }
    return lbl_97_bss_1C0;
}
}
