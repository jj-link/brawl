#pragma force_active on

struct GlobalObj {
    void* vtable;
};

extern "C" {
extern char lbl_27_data_2FF88[];
extern char lbl_27_bss_4B10[0xC];
extern GlobalObj lbl_27_bss_4B1C;
void* fn_27_178E58(void* a, int b);
void __register_global_object(void*, void*, void*);
void fn_27_178E98(void);
}

void fn_27_178E98(void) {
    lbl_27_bss_4B1C.vtable = 0;
    lbl_27_bss_4B1C.vtable = &lbl_27_data_2FF88;
    __register_global_object(&lbl_27_bss_4B1C, (void*)fn_27_178E58, lbl_27_bss_4B10);
}

__declspec(section ".ctors") extern void* const fn_27_178E98_ctor = (void*)fn_27_178E98;
