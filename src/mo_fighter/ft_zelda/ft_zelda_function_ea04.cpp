#pragma force_active on
extern "C" {
extern char lbl_104_bss_1B4[4];
extern char lbl_104_bss_1A8[12];
void fn_104_EA4C(void* p);
void* fn_104_E9C4(void* p, short size);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_104_EA04() {
    fn_104_EA4C(lbl_104_bss_1B4);
    __register_global_object(lbl_104_bss_1B4, (void*)fn_104_E9C4, lbl_104_bss_1A8);
}
}

__declspec(section ".ctors") extern void* const fn_104_EA04_ctor = (void*)fn_104_EA04;
