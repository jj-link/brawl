#pragma force_active on
extern "C" {
extern unsigned char lbl_101_bss_51C[];
extern unsigned char lbl_101_bss_510[];
void fn_101_21728(void*);
void* fn_101_216A0(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_216E0() {
    fn_101_21728(lbl_101_bss_51C);
    __register_global_object(lbl_101_bss_51C,
        reinterpret_cast<void*>(fn_101_216A0), lbl_101_bss_510);
}

__declspec(section ".ctors") extern void* const fn_101_216E0_ctor = (void*)fn_101_216E0;
