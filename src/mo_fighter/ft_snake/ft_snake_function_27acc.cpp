#pragma force_active on
extern "C" {
extern unsigned char lbl_122_bss_4E4[];
extern unsigned char lbl_122_bss_4D8[];
void fn_122_27B14(void*);
void* fn_122_27A8C(void*, short);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_122_27ACC() {
    fn_122_27B14(lbl_122_bss_4E4);
    __register_global_object(lbl_122_bss_4E4, (void*)fn_122_27A8C, lbl_122_bss_4D8);
}

__declspec(section ".ctors") extern void* const fn_122_27ACC_ctor = (void*)fn_122_27ACC;
