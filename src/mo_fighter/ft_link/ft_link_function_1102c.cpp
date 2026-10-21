#pragma force_active on
extern "C" {
extern unsigned char lbl_93_bss_1BC;
extern unsigned char lbl_93_bss_1B0;

void fn_93_11074(void *);
void *fn_93_10FEC(void *, short);
void *__register_global_object(void *, void *, void *);

void fn_93_1102C() {
    fn_93_11074(&lbl_93_bss_1BC);
    __register_global_object(&lbl_93_bss_1BC, (void *)fn_93_10FEC, &lbl_93_bss_1B0);
}
}

__declspec(section ".ctors") extern void* const fn_93_1102C_ctor = (void*)fn_93_1102C;
