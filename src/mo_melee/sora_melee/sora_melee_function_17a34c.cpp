#pragma force_active on

extern "C" {
extern char lbl_27_bss_4B60[0xC];
extern char lbl_27_data_301E0[];
void fn_27_17A30C(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4B6C;

extern "C" void fn_27_17A34C() {
    lbl_27_bss_4B6C.vtable = 0;
    lbl_27_bss_4B6C.vtable = (void*)&lbl_27_data_301E0;
    __register_global_object(&lbl_27_bss_4B6C, (void*)fn_27_17A30C, lbl_27_bss_4B60);
}

__declspec(section ".ctors") extern void* const fn_27_17A34C_ctor = (void*)fn_27_17A34C;
