#pragma force_active on
struct ModuleInfo;

extern "C" {
void fn_96_16BD0(ModuleInfo *module);
void *fn_96_16B48(void *p, short n);
void *__register_global_object(void *object, void *destructor, void *chain);
extern char lbl_96_bss_CCC[4];
extern char lbl_96_bss_CC0[12];
}

extern "C" void fn_96_16B88() {
    fn_96_16BD0((ModuleInfo *)lbl_96_bss_CCC);
    __register_global_object(lbl_96_bss_CCC, (void *)fn_96_16B48, lbl_96_bss_CC0);
}

__declspec(section ".ctors") extern void* const fn_96_16B88_ctor = (void*)fn_96_16B88;
