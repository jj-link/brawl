#pragma force_active on

extern "C" {
char lbl_72_bss_48[];
unsigned char lbl_72_bss_18[];
unsigned char lbl_72_data_F68[];
unsigned char lbl_72_data_F10[];
unsigned char lbl_72_bss_50[];
void __register_global_object(void*, void*, void*);
void* fn_72_3CE8(void*, int);
}

extern "C" void* fn_72_3C24(void) {
    if (!lbl_72_bss_48[0]) {
        *(void**)(lbl_72_bss_50 + 4) = (void*)lbl_72_data_F68;
        lbl_72_bss_50[0] = 1;
        *(void**)(lbl_72_bss_50 + 4) = (void*)lbl_72_data_F10;
        __register_global_object((void*)lbl_72_bss_50, (void*)fn_72_3CE8, (void*)lbl_72_bss_18);
        lbl_72_bss_48[0] = 1;
    }
    return (void*)lbl_72_bss_50;
}
