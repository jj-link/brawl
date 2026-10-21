#pragma force_active on
extern "C" {
extern char __vt__10soNullable[];
extern char lbl_27_data_99150[];
extern char lbl_27_bss_8820[];
extern char lbl_27_bss_8810[];
void fn_27_387518(void);
void *__register_global_object(void *object, void *destructor, void *chain);

void fn_27_387558(void) {
    *(void **)lbl_27_bss_8820 = (void *)__vt__10soNullable;
    lbl_27_bss_8820[4] = 0;
    *(void **)lbl_27_bss_8820 = (void *)lbl_27_data_99150;
    __register_global_object(lbl_27_bss_8820, (void *)fn_27_387518, lbl_27_bss_8810);
}
}

__declspec(section ".ctors") extern void* const fn_27_387558_ctor = (void*)fn_27_387558;
