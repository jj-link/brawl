#pragma force_active on
extern "C" {
extern int lbl_92_bss_274;
extern int lbl_92_bss_268[3];
void fn_92_FF0C(void* object);
void* fn_92_FE84(void* ptr, short count);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_92_FEC4() {
    fn_92_FF0C(&lbl_92_bss_274);
    __register_global_object(&lbl_92_bss_274, (void*)fn_92_FE84, &lbl_92_bss_268);
}

__declspec(section ".ctors") extern void* const fn_92_FEC4_ctor = (void*)fn_92_FEC4;
