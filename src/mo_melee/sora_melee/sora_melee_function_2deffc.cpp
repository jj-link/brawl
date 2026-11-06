#pragma force_active on
extern "C" {
struct GlobalBase {
    void* vtbl;
};
extern char lbl_27_data_7C510[0x40];
extern char lbl_27_bss_73C0[0xC];
extern GlobalBase lbl_27_bss_73CC;
void fn_27_2DEFBC(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_2DEFFC(void) {
    lbl_27_bss_73CC.vtbl = 0;
    lbl_27_bss_73CC.vtbl = &lbl_27_data_7C510;
    __register_global_object(&lbl_27_bss_73CC, fn_27_2DEFBC, lbl_27_bss_73C0);
}
}

__declspec(section ".ctors") extern void* const fn_27_2DEFFC_ctor = (void*)fn_27_2DEFFC;
