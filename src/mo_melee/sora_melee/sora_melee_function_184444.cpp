#pragma force_active on
extern "C" {
struct GlobalObject {
    void* vtable;
};
extern char lbl_27_data_30AA0[0x40];
extern GlobalObject lbl_27_bss_4C8C;
extern char lbl_27_bss_4C80[0xC];
void* fn_27_184404(void*, int);
void __register_global_object(void*, void*, void*);
}

extern "C" void fn_27_184444() {
    lbl_27_bss_4C8C.vtable = 0;
    lbl_27_bss_4C8C.vtable = lbl_27_data_30AA0;
    __register_global_object(&lbl_27_bss_4C8C, (void*)fn_27_184404, lbl_27_bss_4C80);
}

__declspec(section ".ctors") extern void* const fn_27_184444_ctor = (void*)fn_27_184444;
