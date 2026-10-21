#pragma force_active on
extern "C" {
void fn_122_14B78(void* p);
void* __register_global_object(void* object, void* destructor, void* chain);
void* fn_122_14AF0(void* p, short flag);
extern char lbl_122_bss_19C[];
extern char lbl_122_bss_190[];
}

extern "C" void fn_122_14B30() {
    fn_122_14B78(lbl_122_bss_19C);
    __register_global_object(lbl_122_bss_19C, (void*)fn_122_14AF0, lbl_122_bss_190);
}

__declspec(section ".ctors") extern void* const fn_122_14B30_ctor = (void*)fn_122_14B30;
