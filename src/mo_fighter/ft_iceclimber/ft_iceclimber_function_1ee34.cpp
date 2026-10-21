#pragma force_active on
extern "C" {
extern unsigned char lbl_105_bss_4B4[];
extern unsigned char lbl_105_bss_4A8[];
void fn_105_1EE7C(void **);
void *fn_105_1EDF4(void *, short);
void *__register_global_object(void *, void *, void *);
}

extern "C" void fn_105_1EE34() {
    fn_105_1EE7C((void **)lbl_105_bss_4B4);
    __register_global_object(lbl_105_bss_4B4, (void *)fn_105_1EDF4, (void *)lbl_105_bss_4A8);
}

__declspec(section ".ctors") extern void* const fn_105_1EE34_ctor = (void*)fn_105_1EE34;
