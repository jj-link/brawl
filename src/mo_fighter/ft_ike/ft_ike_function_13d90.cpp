#pragma force_active on
extern "C" {
extern unsigned char lbl_119_bss_31C[];
extern unsigned char lbl_119_bss_310[];
extern void fn_119_13DD8(void**);
extern void* fn_119_13D50(void*, short);
extern void __register_global_object(void*, void*, void*);

void fn_119_13D90() {
    fn_119_13DD8((void**)lbl_119_bss_31C);
    __register_global_object(lbl_119_bss_31C, (void*)fn_119_13D50, lbl_119_bss_310);
}
}

__declspec(section ".ctors") extern void* const fn_119_13D90_ctor = (void*)fn_119_13D90;
