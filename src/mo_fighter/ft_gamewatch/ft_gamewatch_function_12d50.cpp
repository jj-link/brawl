#pragma force_active on
extern "C" {
extern unsigned char lbl_107_bss_1CC[];
extern unsigned char lbl_107_bss_1C0[];
void fn_107_12D98(void **);
void *fn_107_12CD0(void *, short);
void *__register_global_object(void *, void *, void *);

void fn_107_12D50(void) {
    fn_107_12D98((void **)lbl_107_bss_1CC);
    __register_global_object(lbl_107_bss_1CC, (void *)fn_107_12CD0, lbl_107_bss_1C0);
}
}

__declspec(section ".ctors") extern void* const fn_107_12D50_ctor = (void*)fn_107_12D50;
