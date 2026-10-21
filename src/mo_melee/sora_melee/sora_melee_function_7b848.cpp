#pragma force_active on
extern "C" {

extern unsigned char __vt__10soNullable[];
extern unsigned char lbl_27_data_92C8[];
extern unsigned char lbl_27_bss_188[];
extern unsigned char lbl_27_bss_178[];
extern void* fn_27_7B808(void*, int);
extern void* __register_global_object(void*, void*, void*);

void fn_27_7B848() {
    *(void**)lbl_27_bss_188 = __vt__10soNullable;
    lbl_27_bss_188[4] = 0;
    *(void**)lbl_27_bss_188 = lbl_27_data_92C8;
    __register_global_object(lbl_27_bss_188, (void*)fn_27_7B808, lbl_27_bss_178);
}

}

__declspec(section ".ctors") extern void* const fn_27_7B848_ctor = (void*)fn_27_7B848;
