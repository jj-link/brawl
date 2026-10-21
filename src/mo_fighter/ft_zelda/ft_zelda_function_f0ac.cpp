#pragma force_active on
extern "C" {
extern unsigned char lbl_104_bss_1D4[4];
extern unsigned char lbl_104_bss_1C8[12];
void fn_104_F0F4(void*);
void* fn_104_F06C(void*, short);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_104_F0AC() {
    fn_104_F0F4(lbl_104_bss_1D4);
    __register_global_object(lbl_104_bss_1D4, (void*)fn_104_F06C, lbl_104_bss_1C8);
}

__declspec(section ".ctors") extern void* const fn_104_F0AC_ctor = (void*)fn_104_F0AC;
