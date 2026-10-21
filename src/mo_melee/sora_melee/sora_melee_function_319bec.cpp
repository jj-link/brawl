#pragma force_active on
extern "C" void fn_27_1E82E8(void*, int);
extern "C" void fn_27_1E847C(void*, int, void*);
extern "C" void fn_27_319C68(void*);
extern "C" int __register_global_object(void*, void (*)(void*), void*);

extern "C" char lbl_27_bss_7B4C[12];
extern "C" char lbl_27_bss_7B40[12];
extern "C" char lbl_27_data_84FE0[24];

extern "C" void fn_27_319BEC() {
    fn_27_1E82E8(lbl_27_bss_7B4C, 0);
    *(void**)(lbl_27_bss_7B4C + 8) = lbl_27_data_84FE0;
    *(void**)(lbl_27_bss_7B4C + 0) = lbl_27_data_84FE0 + 8;
    fn_27_1E847C(lbl_27_bss_7B4C, 0x21, lbl_27_bss_7B4C);
    __register_global_object(lbl_27_bss_7B4C, fn_27_319C68, lbl_27_bss_7B40);
}

__declspec(section ".ctors") extern void* const fn_27_319BEC_ctor = (void*)fn_27_319BEC;
