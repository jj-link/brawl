#pragma force_active on
extern "C" {
extern unsigned char lbl_96_bss_CEC[4];
extern unsigned char lbl_96_bss_CE0[12];
void fn_96_17B00(void* object);
void* fn_96_17A78(void* p, short n);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_96_17AB8(void) {
    fn_96_17B00(lbl_96_bss_CEC);
    __register_global_object(lbl_96_bss_CEC, (void*)fn_96_17A78, lbl_96_bss_CE0);
}
}

__declspec(section ".ctors") extern void* const fn_96_17AB8_ctor = (void*)fn_96_17AB8;
