#pragma force_active on
extern "C" {
extern unsigned char lbl_101_bss_43C[];
extern unsigned char lbl_101_bss_430[];
void fn_101_1CA04(void*);
void* fn_101_1C97C(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_1C9BC() {
    fn_101_1CA04(lbl_101_bss_43C);
    __register_global_object(lbl_101_bss_43C,
        reinterpret_cast<void*>(fn_101_1C97C), lbl_101_bss_430);
}

__declspec(section ".ctors") extern void* const fn_101_1C9BC_ctor = (void*)fn_101_1C9BC;
