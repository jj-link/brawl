#pragma force_active on
extern "C" {
extern unsigned char lbl_96_bss_CDC[];
extern unsigned char lbl_96_bss_CD0[];
void* fn_96_17820(void* object);
void* fn_96_17798(void* p, short n);
void* __register_global_object(void* object, void* destructor, void* chain);

void fn_96_177D8(void) {
    fn_96_17820(lbl_96_bss_CDC);
    __register_global_object(lbl_96_bss_CDC, (void*)fn_96_17798, lbl_96_bss_CD0);
}
}

__declspec(section ".ctors") extern void* const fn_96_177D8_ctor = (void*)fn_96_177D8;
