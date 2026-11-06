#pragma force_active on

extern "C" {
extern char lbl_27_data_8D7D0[];
extern char lbl_27_bss_7F28[12];
void fn_27_34E10C(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_7F34;

extern "C" void fn_27_34E14C(void) {
    lbl_27_bss_7F34.vtable = 0;
    lbl_27_bss_7F34.vtable = (void*)&lbl_27_data_8D7D0;
    __register_global_object(&lbl_27_bss_7F34, (void*)fn_27_34E10C, lbl_27_bss_7F28);
}

__declspec(section ".ctors") extern void* const fn_27_34E14C_ctor = (void*)fn_27_34E14C;
