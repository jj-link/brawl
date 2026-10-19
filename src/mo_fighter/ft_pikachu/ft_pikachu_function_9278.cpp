#pragma force_active on
extern "C" {
extern signed char lbl_98_bss_20C;
extern char lbl_98_bss_210[];
extern char lbl_98_bss_1F4[];
void fn_27_197E44(void*);
void fn_27_197E54(void*, short);
void __register_global_object(void*, void*, void*);

void* fn_98_9278() {
    if (!lbl_98_bss_20C) {
        fn_27_197E44(lbl_98_bss_210);
        __register_global_object(lbl_98_bss_210, (void*)fn_27_197E54, lbl_98_bss_1F4);
        lbl_98_bss_20C = 1;
    }
    return lbl_98_bss_210;
}
}
