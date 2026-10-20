#pragma force_active on
extern "C" {

extern signed char lbl_68_bss_30;
extern unsigned char lbl_68_bss_38[8];
extern unsigned char lbl_68_bss_18[12];
extern unsigned char lbl_68_data_10A0[0x38];
extern unsigned char lbl_68_data_10F8[0x38];
void* fn_68_56B4(void* p, int n);
void* __register_global_object(void* object, void* destructor, void* chain);

void* fn_68_55F0() {
    if (lbl_68_bss_30 == 0) {
        *(void**)(lbl_68_bss_38 + 4) = (void*)lbl_68_data_10F8;
        lbl_68_bss_38[0] = 1;
        *(void**)(lbl_68_bss_38 + 4) = (void*)lbl_68_data_10A0;
        __register_global_object(lbl_68_bss_38, fn_68_56B4, lbl_68_bss_18);
        lbl_68_bss_30 = 1;
    }
    return (void*)lbl_68_bss_38;
}

}
