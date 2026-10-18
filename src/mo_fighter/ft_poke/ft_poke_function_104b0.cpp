#pragma force_active on
extern "C" {
typedef struct { void* a; void* b; } Struct1F8;
extern signed char lbl_116_bss_1F4;
extern Struct1F8 lbl_116_bss_1F8;
extern unsigned char lbl_116_bss_17C[];
extern unsigned char lbl_116_data_26C4[];
extern unsigned char lbl_116_data_2698[];
extern unsigned char lbl_116_data_2630[];
extern unsigned char lbl_116_data_74F8[];
void* fn_116_10550(void*);
void* __register_global_object(void*, void*, void*);

void* fn_116_104B0(void) {
    if (lbl_116_bss_1F4 == 0) {
        lbl_116_bss_1F8.a = lbl_116_data_26C4;
        lbl_116_bss_1F8.b = lbl_116_data_2698;
        lbl_116_bss_1F8.a = lbl_116_data_2630;
        lbl_116_bss_1F8.b = lbl_116_data_2630 + 0x10;
        lbl_116_bss_1F8.a = lbl_116_data_74F8;
        lbl_116_bss_1F8.b = lbl_116_data_74F8 + 0x10;
        __register_global_object(&lbl_116_bss_1F8, fn_116_10550, &lbl_116_bss_17C);
        lbl_116_bss_1F4 = 1;
    }
    return &lbl_116_bss_1F8;
}
}
