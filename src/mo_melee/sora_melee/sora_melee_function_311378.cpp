#pragma force_active on
extern "C" {
struct GlobalObject {
    void* vtbl;
};
extern char lbl_27_data_837E8[];
extern char lbl_27_bss_7B20[0xC];
extern GlobalObject lbl_27_bss_7B2C;
void fn_27_311338(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_311378() {
    lbl_27_bss_7B2C.vtbl = 0;
    lbl_27_bss_7B2C.vtbl = lbl_27_data_837E8;
    __register_global_object(&lbl_27_bss_7B2C, fn_27_311338, lbl_27_bss_7B20);
}
}

__declspec(section ".ctors") extern void* const fn_27_311378_ctor = (void*)fn_27_311378;
