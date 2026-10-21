#pragma force_active on
extern "C" {
extern unsigned char lbl_122_bss_2DC;
extern unsigned char lbl_122_bss_2D0;

void fn_122_1AEF4(void *);
void *fn_122_1AE6C(void *, short);
void *__register_global_object(void *, void *, void *);

void fn_122_1AEAC() {
    fn_122_1AEF4(&lbl_122_bss_2DC);
    __register_global_object(&lbl_122_bss_2DC,
                             reinterpret_cast<void *>(fn_122_1AE6C),
                             &lbl_122_bss_2D0);
}
}

__declspec(section ".ctors") extern void* const fn_122_1AEAC_ctor = (void*)fn_122_1AEAC;
