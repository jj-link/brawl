#pragma force_active on
extern "C" {
extern unsigned char lbl_101_bss_50C[];
extern unsigned char lbl_101_bss_500[];
void fn_101_20E44(void*);
void* fn_101_20DBC(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_20DFC() {
    fn_101_20E44(lbl_101_bss_50C);
    __register_global_object(
        lbl_101_bss_50C,
        reinterpret_cast<void*>(fn_101_20DBC),
        lbl_101_bss_500);
}

__declspec(section ".ctors") extern void* const fn_101_20DFC_ctor = (void*)fn_101_20DFC;
