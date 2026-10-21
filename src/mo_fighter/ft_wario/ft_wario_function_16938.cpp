#pragma force_active on

extern "C" {
extern unsigned char lbl_110_bss_324[];
extern unsigned char lbl_110_bss_318[];
void fn_110_16980(void*);
void* fn_110_168F8(void*, short);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_110_16938(void) {
    fn_110_16980(lbl_110_bss_324);
    __register_global_object(
        lbl_110_bss_324,
        (void*)fn_110_168F8,
        lbl_110_bss_318
    );
}

__declspec(section ".ctors") extern void* const fn_110_16938_ctor = (void*)fn_110_16938;
