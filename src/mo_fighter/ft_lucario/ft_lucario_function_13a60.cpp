#pragma force_active on

extern "C" {
extern signed char lbl_118_bss_364;
extern unsigned char lbl_118_bss_368[8];
extern char lbl_118_data_7304[0x38];
extern char lbl_118_data_72B0[0x38];
extern unsigned char lbl_118_bss_328[12];
void fn_118_13B24(void*, short);
void __register_global_object(void*, void (*)(void*, short), void*);
}

extern "C" void* fn_118_13A60() {
    if (lbl_118_bss_364 == 0) {
        *reinterpret_cast<void**>(lbl_118_bss_368 + 4) = lbl_118_data_7304;
        lbl_118_bss_368[0] = 1;
        *reinterpret_cast<void**>(lbl_118_bss_368 + 4) = lbl_118_data_72B0;
        __register_global_object(lbl_118_bss_368, fn_118_13B24, lbl_118_bss_328);
        lbl_118_bss_364 = 1;
    }
    return lbl_118_bss_368;
}
