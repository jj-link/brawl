#pragma force_active on
extern "C" {
void fn_122_14640(void*);
void* fn_122_145B8(void*, short);
void* __register_global_object(void*, void*, void*);
extern unsigned char lbl_122_bss_18C[4];
extern unsigned char lbl_122_bss_180[12];
}

extern "C" void fn_122_145F8() {
    fn_122_14640(lbl_122_bss_18C);
    __register_global_object(lbl_122_bss_18C,
                             reinterpret_cast<void*>(fn_122_145B8),
                             lbl_122_bss_180);
}

__declspec(section ".ctors") extern void* const fn_122_145F8_ctor = (void*)fn_122_145F8;
