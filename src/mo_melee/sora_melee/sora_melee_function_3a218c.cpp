#pragma force_active on

extern "C" {
extern unsigned char lbl_27_data_9C800[0x40];
extern unsigned char lbl_27_bss_8A28[0xC];
void fn_27_3A214C(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_8A34;

extern "C" void fn_27_3A218C(void) {
    lbl_27_bss_8A34.vtable = 0;
    lbl_27_bss_8A34.vtable = (void*)lbl_27_data_9C800;
    __register_global_object(&lbl_27_bss_8A34, fn_27_3A214C, lbl_27_bss_8A28);
}

__declspec(section ".ctors") extern void* const fn_27_3A218C_ctor = (void*)fn_27_3A218C;
