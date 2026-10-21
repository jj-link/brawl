#pragma force_active on
extern "C" {
extern unsigned char lbl_101_bss_344;
extern unsigned char lbl_101_bss_338;
void fn_101_16644(void*);
void* fn_101_165BC(void*, short);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_101_165FC() {
    fn_101_16644(&lbl_101_bss_344);
    __register_global_object(&lbl_101_bss_344,
        reinterpret_cast<void*>(fn_101_165BC), &lbl_101_bss_338);
}

__declspec(section ".ctors") extern void* const fn_101_165FC_ctor = (void*)fn_101_165FC;
