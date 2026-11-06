#pragma force_active on

extern "C" {
extern void* lbl_27_data_30F58;
extern unsigned char lbl_27_bss_4D40[12];
void* fn_27_186FB4(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern "C" GlobalObject lbl_27_bss_4D4C;

extern "C" void fn_27_186FF4(void) {
    lbl_27_bss_4D4C.vtable = 0;
    lbl_27_bss_4D4C.vtable = (void*)&lbl_27_data_30F58;
    __register_global_object(&lbl_27_bss_4D4C, (void*)fn_27_186FB4, lbl_27_bss_4D40);
}

__declspec(section ".ctors") extern void* const fn_27_186FF4_ctor = (void*)fn_27_186FF4;
