#pragma force_active on
extern "C" {
extern unsigned char lbl_117_bss_24C[];
extern unsigned char lbl_117_bss_240[];
void fn_117_EF00(void* dst);
void* fn_117_EE78(void* object, short deleting);
void __register_global_object(void*, void*, void*);

void fn_117_EEB8(void) {
    fn_117_EF00(lbl_117_bss_24C);
    __register_global_object(lbl_117_bss_24C, reinterpret_cast<void*>(fn_117_EE78), lbl_117_bss_240);
}
}

__declspec(section ".ctors") extern void* const fn_117_EEB8_ctor = (void*)fn_117_EEB8;
