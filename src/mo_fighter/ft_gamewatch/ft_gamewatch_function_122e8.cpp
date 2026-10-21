#pragma force_active on
extern "C" {
extern int lbl_107_bss_17C;
extern int lbl_107_bss_170;
void fn_107_12330(void *obj);
void *fn_107_122A8(void *ptr, short count);
void *__register_global_object(void *object, void *destructor, void *chain);

void fn_107_122E8() {
    fn_107_12330(&lbl_107_bss_17C);
    __register_global_object(&lbl_107_bss_17C, (void *)fn_107_122A8, &lbl_107_bss_170);
}
}

__declspec(section ".ctors") extern void* const fn_107_122E8_ctor = (void*)fn_107_122E8;
