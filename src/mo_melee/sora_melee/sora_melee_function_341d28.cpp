#pragma force_active on

extern "C" {
extern char lbl_27_data_8C3D0[];
extern char lbl_27_bss_7E90[0xC];
void fn_27_341CE8(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_7E9C;

extern "C" void fn_27_341D28(void) {
    lbl_27_bss_7E9C.vtable = 0;
    lbl_27_bss_7E9C.vtable = (void*)&lbl_27_data_8C3D0;
    __register_global_object(&lbl_27_bss_7E9C, (void*)fn_27_341CE8, lbl_27_bss_7E90);
}

__declspec(section ".ctors") extern void* const fn_27_341D28_ctor = (void*)fn_27_341D28;
