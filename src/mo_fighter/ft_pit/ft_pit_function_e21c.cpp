#pragma force_active on
extern "C" {
extern char lbl_112_bss_1BC[4];
extern char lbl_112_bss_1B0[12];
void fn_112_E264(void* p);
void* fn_112_E1DC(void* p, short flag);
void* __register_global_object(void* object, void* destructor, void* chain);
}

extern "C" void fn_112_E21C() {
    fn_112_E264(lbl_112_bss_1BC);
    __register_global_object(lbl_112_bss_1BC, (void*)fn_112_E1DC, lbl_112_bss_1B0);
}

__declspec(section ".ctors") extern void* const fn_112_E21C_ctor = (void*)fn_112_E21C;
