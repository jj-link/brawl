#pragma force_active on
extern "C" {
struct GlobalObj {
    void* vtable;
};
extern GlobalObj lbl_27_bss_4D1C;
extern char lbl_27_bss_4D10[0xC];
extern char lbl_27_data_30DF0[0x40];
void* fn_27_1868DC(void*, int);
void* __register_global_object(void*, void*, void*);
}

extern "C" void fn_27_18691C() {
    lbl_27_bss_4D1C.vtable = 0;
    lbl_27_bss_4D1C.vtable = (void*)&lbl_27_data_30DF0;
    __register_global_object(&lbl_27_bss_4D1C, (void*)fn_27_1868DC, (void*)lbl_27_bss_4D10);
}

__declspec(section ".ctors") extern void* const fn_27_18691C_ctor = (void*)fn_27_18691C;
