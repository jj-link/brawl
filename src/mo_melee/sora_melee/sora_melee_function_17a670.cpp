#pragma force_active on
extern "C" {
struct GlobalBase {
    void* vtbl;
};
extern char lbl_27_data_302E0[];
extern GlobalBase lbl_27_bss_4B8C;
extern char lbl_27_bss_4B80[12];
void fn_27_17A630(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_17A670() {
    lbl_27_bss_4B8C.vtbl = 0;
    lbl_27_bss_4B8C.vtbl = lbl_27_data_302E0;
    __register_global_object(&lbl_27_bss_4B8C, (void*)fn_27_17A630, (void*)lbl_27_bss_4B80);
}
}

__declspec(section ".ctors") extern void* const fn_27_17A670_ctor = (void*)fn_27_17A670;
