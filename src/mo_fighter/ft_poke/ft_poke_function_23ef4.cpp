#pragma force_active on
extern "C" {
void fn_116_23F3C(void* self);
void* fn_116_23EB4(void* ptr, short count);
void* __register_global_object(void* object, void* destructor, void* chain);
extern void* lbl_116_bss_62C;
extern char lbl_116_bss_620[12];
}

extern "C" void fn_116_23EF4() {
    fn_116_23F3C(&lbl_116_bss_62C);
    __register_global_object(&lbl_116_bss_62C, (void*)fn_116_23EB4, lbl_116_bss_620);
}

__declspec(section ".ctors") extern void* const fn_116_23EF4_ctor = (void*)fn_116_23EF4;
