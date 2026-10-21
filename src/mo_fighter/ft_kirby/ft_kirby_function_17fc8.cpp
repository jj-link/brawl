#pragma force_active on
extern "C" {
extern unsigned char lbl_96_bss_CFC[];
extern unsigned char lbl_96_bss_CF0[];
void fn_96_18010(void* object);
void* fn_96_17F88(void* p, short n);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_96_17FC8(void) {
    fn_96_18010(lbl_96_bss_CFC);
    __register_global_object(lbl_96_bss_CFC, (void*)fn_96_17F88, lbl_96_bss_CF0);
}
}

__declspec(section ".ctors") extern void* const fn_96_17FC8_ctor = (void*)fn_96_17FC8;
