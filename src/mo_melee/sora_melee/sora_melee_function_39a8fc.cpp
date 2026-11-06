#pragma force_active on

extern "C" {
extern char lbl_27_data_9B5A0[0x40];
extern char lbl_27_bss_8948[0xC];
void* fn_27_39A8BC(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject8954 {
    void* vtable;
};

extern GlobalObject8954 lbl_27_bss_8954;

extern "C" void fn_27_39A8FC(void) {
    lbl_27_bss_8954.vtable = 0;
    lbl_27_bss_8954.vtable = (void*)&lbl_27_data_9B5A0;
    __register_global_object(&lbl_27_bss_8954, (void*)fn_27_39A8BC, lbl_27_bss_8948);
}

__declspec(section ".ctors") extern void* const fn_27_39A8FC_ctor = (void*)fn_27_39A8FC;
