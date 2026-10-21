#pragma force_active on
extern "C" {
void fn_112_E138(void* p);
void* fn_112_E0A4(void* p, short n);
void* __register_global_object(void* obj, void* dtor, void* chain);

extern int lbl_112_bss_1AC;
extern char lbl_112_bss_1A0[12];

void fn_112_E0F0(void) {
    fn_112_E138(&lbl_112_bss_1AC);
    __register_global_object(&lbl_112_bss_1AC, (void*)fn_112_E0A4, lbl_112_bss_1A0);
}
}

__declspec(section ".ctors") extern void* const fn_112_E0F0_ctor = (void*)fn_112_E0F0;
