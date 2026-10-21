#pragma force_active on
extern "C" {
extern unsigned char lbl_116_bss_4CC;
extern unsigned char lbl_116_bss_4C0;
void fn_116_1B62C(void*);
void* fn_116_1B5A4(void*, short);
void* __register_global_object(void*, void*, void*);

void fn_116_1B5E4(void) {
    fn_116_1B62C(&lbl_116_bss_4CC);
    __register_global_object(&lbl_116_bss_4CC, (void*)fn_116_1B5A4, (void*)&lbl_116_bss_4C0);
}
}

__declspec(section ".ctors") extern void* const fn_116_1B5E4_ctor = (void*)fn_116_1B5E4;
