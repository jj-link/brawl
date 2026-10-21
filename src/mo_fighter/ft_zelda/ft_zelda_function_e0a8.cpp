#pragma force_active on
extern "C" {
extern int lbl_104_bss_194;
extern int lbl_104_bss_188;

void fn_104_E0F0(void* p);
void* fn_104_E064(void* p, short flag);
void* __register_global_object(void* object, void* (*destructor)(void*, short), void* chain);

void fn_104_E0A8() {
    fn_104_E0F0(&lbl_104_bss_194);
    __register_global_object(&lbl_104_bss_194, fn_104_E064, &lbl_104_bss_188);
}
}

__declspec(section ".ctors") extern void* const fn_104_E0A8_ctor = (void*)fn_104_E0A8;
