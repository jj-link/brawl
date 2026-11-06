#pragma force_active on

extern "C" {
extern char lbl_27_data_316C8[];
extern char lbl_27_bss_4E20[12];
void fn_27_18A9D0(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtbl;
};

extern "C" GlobalObject lbl_27_bss_4E2C;

extern "C" void fn_27_18AA10() {
    lbl_27_bss_4E2C.vtbl = 0;
    lbl_27_bss_4E2C.vtbl = (void*)&lbl_27_data_316C8;
    __register_global_object(&lbl_27_bss_4E2C, (void*)fn_27_18A9D0, lbl_27_bss_4E20);
}

__declspec(section ".ctors") extern void* const fn_27_18AA10_ctor = (void*)fn_27_18AA10;
