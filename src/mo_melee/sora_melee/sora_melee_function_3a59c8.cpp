#pragma force_active on

extern "C" {
extern char lbl_27_data_9D0E0[];
extern char lbl_27_bss_8A80[12];
void* fn_27_3A5988(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_8A8C;

extern "C" void fn_27_3A59C8(void) {
    lbl_27_bss_8A8C.vtable = 0;
    lbl_27_bss_8A8C.vtable = (void*)&lbl_27_data_9D0E0;
    __register_global_object(&lbl_27_bss_8A8C, (void*)fn_27_3A5988, lbl_27_bss_8A80);
}

__declspec(section ".ctors") extern void* const fn_27_3A59C8_ctor = (void*)fn_27_3A59C8;
