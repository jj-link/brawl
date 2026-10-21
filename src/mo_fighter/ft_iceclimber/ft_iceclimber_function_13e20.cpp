#pragma force_active on
extern "C" {
extern unsigned char lbl_105_bss_29C;
extern unsigned char lbl_105_bss_290;
void fn_105_13E68(void*);
void* fn_105_13DE0(void*, short);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_105_13E20() {
    fn_105_13E68(&lbl_105_bss_29C);
    __register_global_object(
        &lbl_105_bss_29C,
        (void*)fn_105_13DE0,
        &lbl_105_bss_290
    );
}

__declspec(section ".ctors") extern void* const fn_105_13E20_ctor = (void*)fn_105_13E20;
