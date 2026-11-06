#pragma force_active on
extern "C" {
extern char lbl_27_data_307B0[];
extern char lbl_27_bss_4C20[0xC];
struct GlobalObject {
    void* vtable;
};
extern GlobalObject lbl_27_bss_4C2C;
void fn_27_1810B8(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_1810F8(void) {
    lbl_27_bss_4C2C.vtable = 0;
    lbl_27_bss_4C2C.vtable = (void*)&lbl_27_data_307B0;
    __register_global_object(&lbl_27_bss_4C2C, (void*)fn_27_1810B8, lbl_27_bss_4C20);
}
}

__declspec(section ".ctors") extern void* const fn_27_1810F8_ctor = (void*)fn_27_1810F8;
