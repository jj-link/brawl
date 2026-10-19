#pragma force_active on
extern "C" {
extern signed char lbl_117_bss_21C;
extern unsigned char lbl_117_bss_220[];
extern unsigned char lbl_117_bss_204[];
void fn_27_197E44(void*);
void fn_27_197E54(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void* fn_117_893C() {
    if (lbl_117_bss_21C == 0) {
        fn_27_197E44(lbl_117_bss_220);
        __register_global_object(lbl_117_bss_220,
            reinterpret_cast<void*>(fn_27_197E54), lbl_117_bss_204);
        lbl_117_bss_21C = 1;
    }
    return lbl_117_bss_220;
}
