#pragma force_active on

extern "C" {
extern char lbl_27_data_30FD8[];
extern char lbl_27_bss_4D50[0xC];
extern void* lbl_27_bss_4D5C;

void* fn_27_187174(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_1871B4(void) {
    lbl_27_bss_4D5C = 0;
    lbl_27_bss_4D5C = lbl_27_data_30FD8;
    __register_global_object(
        &lbl_27_bss_4D5C,
        (void*)fn_27_187174,
        lbl_27_bss_4D50
    );
}
}

__declspec(section ".ctors") extern void* const fn_27_1871B4_ctor = (void*)fn_27_1871B4;
