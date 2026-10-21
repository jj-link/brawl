#pragma force_active on
extern "C" {
void fn_117_22F3C(unsigned char** out);
extern unsigned char* lbl_117_bss_4F4;
extern unsigned char lbl_117_bss_4E8[];
void* fn_117_22EB4(void* object, short deleting);
void __register_global_object(void*, void*, void*);

void fn_117_22EF4(void) {
    fn_117_22F3C(&lbl_117_bss_4F4);
    __register_global_object(&lbl_117_bss_4F4, reinterpret_cast<void*>(fn_117_22EB4), lbl_117_bss_4E8);
}
}

__declspec(section ".ctors") extern void* const fn_117_22EF4_ctor = (void*)fn_117_22EF4;
