#pragma force_active on
extern "C" {
extern signed char lbl_100_bss_32C;
extern unsigned char lbl_100_bss_330[8];
extern unsigned char lbl_100_bss_2D8[12];
extern char lbl_100_data_7260[0x38];
extern char lbl_100_data_720C[0x38];
void fn_100_131EC(void*, short);
void __register_global_object(void*, void (*)(void*, short), void*);
}

extern "C" void* fn_100_13128() {
    if (lbl_100_bss_32C == 0) {
        *reinterpret_cast<void**>(lbl_100_bss_330 + 4) = lbl_100_data_7260;
        lbl_100_bss_330[0] = 1;
        *reinterpret_cast<void**>(lbl_100_bss_330 + 4) = lbl_100_data_720C;
        __register_global_object(lbl_100_bss_330, fn_100_131EC, lbl_100_bss_2D8);
        lbl_100_bss_32C = 1;
    }
    return lbl_100_bss_330;
}
