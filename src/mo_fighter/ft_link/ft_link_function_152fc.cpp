#pragma force_active on
extern "C" void fn_93_15344(void *object);
extern "C" void *fn_93_152BC(void *slot, short destroy);
extern "C" void *__register_global_object(void *object, void *destructor, void *chain);

extern "C" char lbl_93_bss_284[4];
extern "C" char lbl_93_bss_278[12];

extern "C" void fn_93_152FC(void) {
    fn_93_15344(lbl_93_bss_284);
    __register_global_object(lbl_93_bss_284, (void *)fn_93_152BC, lbl_93_bss_278);
}

__declspec(section ".ctors") extern void* const fn_93_152FC_ctor = (void*)fn_93_152FC;
