#pragma force_active on
extern "C" {
extern int lbl_41_bss_2A4;
extern int lbl_41_bss_298[3];
void fn_41_351F4(void* p);
void* fn_41_3516C(void* p, short flags);
void __register_global_object(void* obj, void* (*dtor)(void*, short), void* regmem);

void fn_41_351AC() {
    fn_41_351F4(&lbl_41_bss_2A4);
    __register_global_object(&lbl_41_bss_2A4, fn_41_3516C, lbl_41_bss_298);
}
}

__declspec(section ".ctors") extern void* const fn_41_351AC_ctor = (void*)fn_41_351AC;
