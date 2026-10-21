#pragma force_active on
extern "C" {
extern unsigned char lbl_107_bss_1BC[];
extern unsigned char lbl_107_bss_1B0[];
void fn_107_12B1C(void*);
void* fn_107_12A94(void*, short);
void* __register_global_object(void*, void*, void*);

void fn_107_12AD4(void) {
    fn_107_12B1C(lbl_107_bss_1BC);
    __register_global_object(lbl_107_bss_1BC, (void*)fn_107_12A94, lbl_107_bss_1B0);
}
}

__declspec(section ".ctors") extern void* const fn_107_12AD4_ctor = (void*)fn_107_12AD4;
