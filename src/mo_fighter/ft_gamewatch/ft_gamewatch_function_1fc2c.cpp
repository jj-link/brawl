#pragma force_active on
extern "C" {
extern char lbl_107_bss_434[];
extern char lbl_107_bss_428[];
void fn_107_1FC74(void **r3);
void fn_107_1FBEC(void *ptr, short flag);
void *__register_global_object(void *object, void *destructor, void *chain);

void fn_107_1FC2C() {
    fn_107_1FC74((void **)lbl_107_bss_434);
    __register_global_object(lbl_107_bss_434, (void *)fn_107_1FBEC, lbl_107_bss_428);
}
}

__declspec(section ".ctors") extern void* const fn_107_1FC2C_ctor = (void*)fn_107_1FC2C;
