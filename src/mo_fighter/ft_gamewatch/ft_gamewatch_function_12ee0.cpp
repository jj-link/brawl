#pragma force_active on
extern "C" {
void fn_107_12F28(void*);
void* fn_107_12EA0(void*, short);
void* __register_global_object(void*, void*, void*);
extern char lbl_107_bss_1DC;
extern char lbl_107_bss_1D0;
void fn_107_12EE0(void);
}

extern "C" void fn_107_12EE0(void) {
    fn_107_12F28(&lbl_107_bss_1DC);
    __register_global_object(&lbl_107_bss_1DC, (void*)fn_107_12EA0, &lbl_107_bss_1D0);
}

__declspec(section ".ctors") extern void* const fn_107_12EE0_ctor = (void*)fn_107_12EE0;
