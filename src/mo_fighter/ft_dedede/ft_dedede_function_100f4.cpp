#pragma force_active on
extern "C" {
extern unsigned int lbl_117_bss_28C;
extern unsigned char lbl_117_bss_280[];
void fn_117_1013C(void*);
void* fn_117_100B4(void*, short);
void __register_global_object(void*, void*, void*);

void fn_117_100F4(void) {
    fn_117_1013C(&lbl_117_bss_28C);
    __register_global_object(&lbl_117_bss_28C, reinterpret_cast<void*>(fn_117_100B4), lbl_117_bss_280);
}
}

__declspec(section ".ctors") extern void* const fn_117_100F4_ctor = (void*)fn_117_100F4;
