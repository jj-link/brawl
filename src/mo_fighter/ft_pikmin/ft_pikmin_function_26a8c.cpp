#pragma force_active on
extern "C" {
extern unsigned char lbl_113_bss_25C[];
extern unsigned char lbl_113_bss_250[];
extern void fn_113_26AD4(void*);
extern void* fn_113_26A4C(void*, short);
extern void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_113_26A8C(void)
{
    fn_113_26AD4(lbl_113_bss_25C);
    __register_global_object(lbl_113_bss_25C, (void*)fn_113_26A4C,
                             lbl_113_bss_250);
}

__declspec(section ".ctors") extern void* const fn_113_26A8C_ctor = (void*)fn_113_26A8C;
