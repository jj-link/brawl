#pragma force_active on
#pragma opt_common_subs off

extern "C" {
extern void* lbl_27_bss_4D3C;
extern char lbl_27_data_30EE0[];
extern char lbl_27_bss_4D30[];

void fn_27_186EA4(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_186EE4(void) {
    lbl_27_bss_4D3C = 0;
    lbl_27_bss_4D3C = lbl_27_data_30EE0;
    __register_global_object(
        &lbl_27_bss_4D3C,
        (void*)fn_27_186EA4,
        lbl_27_bss_4D30
    );
}
}

__declspec(section ".ctors") extern void* const fn_27_186EE4_ctor = (void*)fn_27_186EE4;
