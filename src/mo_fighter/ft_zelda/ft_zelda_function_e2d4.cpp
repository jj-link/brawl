#pragma force_active on
extern "C" {
extern unsigned char lbl_104_bss_1A4;
extern unsigned char lbl_104_bss_198[12];

void fn_104_E31C(void*);
void* fn_104_E294(void*, short);
void* __register_global_object(void*, void*, void*);

void fn_104_E2D4() {
    fn_104_E31C(&lbl_104_bss_1A4);
    __register_global_object(
        &lbl_104_bss_1A4,
        (void*)fn_104_E294,
        lbl_104_bss_198
    );
}
}

__declspec(section ".ctors") extern void* const fn_104_E2D4_ctor = (void*)fn_104_E2D4;
