#pragma force_active on
extern "C" {
void fn_122_14FC4(void* p);
void* fn_122_14F3C(void* p, short n);
void* __register_global_object(void* object, void* destructor, void* chain);
extern int lbl_122_bss_1AC;
extern char lbl_122_bss_1A0[12];
}

extern "C" void fn_122_14F7C() {
    fn_122_14FC4(&lbl_122_bss_1AC);
    __register_global_object(&lbl_122_bss_1AC, (void*)fn_122_14F3C, lbl_122_bss_1A0);
}

__declspec(section ".ctors") extern void* const fn_122_14F7C_ctor = (void*)fn_122_14F7C;
