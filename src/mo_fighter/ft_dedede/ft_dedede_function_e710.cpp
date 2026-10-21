#pragma force_active on
extern "C" {
extern unsigned char lbl_117_bss_23C[];
extern unsigned char lbl_117_bss_230[];
void fn_117_E758(void*);
void* fn_117_E6C8(void*, short);
void __register_global_object(void*, void*, void*);

void fn_117_E710(void) {
    fn_117_E758(lbl_117_bss_23C);
    __register_global_object(lbl_117_bss_23C, reinterpret_cast<void*>(fn_117_E6C8), lbl_117_bss_230);
}
}

__declspec(section ".ctors") extern void* const fn_117_E710_ctor = (void*)fn_117_E710;
