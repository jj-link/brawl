#pragma force_active on

extern "C" {
struct GlobalObj {
    void* vtable;
};
extern GlobalObj lbl_27_bss_4C3C;
extern char lbl_27_data_30850[];
extern char lbl_27_bss_4C30[0xC];
void* fn_27_182270(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_1822B0();
}

void fn_27_1822B0() {
    lbl_27_bss_4C3C.vtable = 0;
    lbl_27_bss_4C3C.vtable = lbl_27_data_30850;
    __register_global_object(&lbl_27_bss_4C3C, (void*)fn_27_182270, lbl_27_bss_4C30);
}

__declspec(section ".ctors") extern void* const fn_27_1822B0_ctor = (void*)fn_27_1822B0;
