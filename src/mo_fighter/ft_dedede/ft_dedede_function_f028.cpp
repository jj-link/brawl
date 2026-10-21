#pragma force_active on
extern "C" {
extern unsigned char lbl_117_bss_25C[];
extern unsigned char lbl_117_bss_250[];
void fn_117_F070(void*);
void* fn_117_EFE8(void*, short);
void __register_global_object(void*, void*, void*);

void fn_117_F028(void) {
    fn_117_F070(lbl_117_bss_25C);
    __register_global_object(lbl_117_bss_25C, reinterpret_cast<void*>(fn_117_EFE8), lbl_117_bss_250);
}
}

__declspec(section ".ctors") extern void* const fn_117_F028_ctor = (void*)fn_117_F028;
