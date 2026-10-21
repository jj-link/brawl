#pragma force_active on
extern "C" {
extern int lbl_112_bss_1CC;
extern char lbl_112_bss_1C0[12];

void fn_112_E4C4(void* p);
void* fn_112_E43C(void* p, short n);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_112_E47C() {
    fn_112_E4C4(&lbl_112_bss_1CC);
    __register_global_object(&lbl_112_bss_1CC, (void*)fn_112_E43C, lbl_112_bss_1C0);
}
}

__declspec(section ".ctors") extern void* const fn_112_E47C_ctor = (void*)fn_112_E47C;
