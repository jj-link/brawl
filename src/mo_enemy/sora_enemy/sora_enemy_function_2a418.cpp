#pragma force_active on
extern "C" void fn_41_28C90(void* p);
extern "C" void* fn_41_28CA4(void* p, short n);
extern "C" void __register_global_object(void* obj, void* (*dtor)(void*, short), void* regmem);

extern "C" char lbl_41_bss_1BC[12];
extern "C" char lbl_41_bss_1B0[12];

extern "C" void fn_41_2A418() {
    fn_41_28C90(lbl_41_bss_1BC);
    __register_global_object(lbl_41_bss_1BC, fn_41_28CA4, lbl_41_bss_1B0);
}

__declspec(section ".ctors") extern void* const fn_41_2A418_ctor = (void*)fn_41_2A418;
