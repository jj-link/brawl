#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern char lbl_27_data_2E8A0[];
extern char lbl_27_bss_48A8[12];
extern GlobalObject lbl_27_bss_48B4;
void fn_27_166478(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_1664B8();
}

extern "C" void fn_27_1664B8(void) {
    lbl_27_bss_48B4.vtable = 0;
    lbl_27_bss_48B4.vtable = (void*)&lbl_27_data_2E8A0;
    __register_global_object(&lbl_27_bss_48B4, (void*)fn_27_166478, lbl_27_bss_48A8);
}

__declspec(section ".ctors") extern void* const fn_27_1664B8_ctor = (void*)fn_27_1664B8;
