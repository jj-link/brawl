#pragma force_active on
extern "C" {
void fn_115_1B98C(void **object);
void *fn_115_1B904(void *self, short flag);
void *__register_global_object(void *object, void *destructor, void *chain);
extern void *lbl_115_bss_444;
extern char lbl_115_bss_438[];
}

extern "C" void fn_115_1B944() {
    fn_115_1B98C(&lbl_115_bss_444);
    __register_global_object(&lbl_115_bss_444, (void *)fn_115_1B904, lbl_115_bss_438);
}

__declspec(section ".ctors") extern void* const fn_115_1B944_ctor = (void*)fn_115_1B944;
