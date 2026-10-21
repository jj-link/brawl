#pragma force_active on
extern "C" {
extern char lbl_105_bss_31C[4];
extern char lbl_105_bss_310[12];
void fn_105_16174(void *object);
void *fn_105_160EC(void *p, short flag);
void *__register_global_object(void *object, void *destructor, void *chain);

void fn_105_1612C(void) {
    fn_105_16174(lbl_105_bss_31C);
    __register_global_object(lbl_105_bss_31C, (void *)fn_105_160EC, lbl_105_bss_310);
}
}

__declspec(section ".ctors") extern void* const fn_105_1612C_ctor = (void*)fn_105_1612C;
