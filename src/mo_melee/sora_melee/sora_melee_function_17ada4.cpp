#pragma force_active on

extern "C" {
extern char lbl_27_data_303C0[];
extern char lbl_27_bss_4BA0[0xC];
void fn_27_17AD64(void*, int);
void __register_global_object(void*, void*, void*);
}

struct GlobalObject {
    void* vtable;
};

extern GlobalObject lbl_27_bss_4BAC;

extern "C" void fn_27_17ADA4(void) {
    lbl_27_bss_4BAC.vtable = 0;
    lbl_27_bss_4BAC.vtable = (void*)&lbl_27_data_303C0;
    __register_global_object(&lbl_27_bss_4BAC, (void*)fn_27_17AD64, lbl_27_bss_4BA0);
}

__declspec(section ".ctors") extern void* const fn_27_17ADA4_ctor = (void*)fn_27_17ADA4;
