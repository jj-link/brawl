#pragma force_active on
extern "C" {
struct GlobalObject {
    void* vtable;
};
extern unsigned char lbl_27_data_45D88[];
extern GlobalObject lbl_27_bss_511C;
extern unsigned char lbl_27_bss_5110[0xC];
void *fn_27_1DE0CC(void *, int);
void __register_global_object(void *, void *, void *);

void fn_27_1DE10C(void) {
    lbl_27_bss_511C.vtable = 0;
    lbl_27_bss_511C.vtable = (void*)&lbl_27_data_45D88;
    __register_global_object(&lbl_27_bss_511C, (void*)fn_27_1DE0CC, lbl_27_bss_5110);
}
}

__declspec(section ".ctors") extern void* const fn_27_1DE10C_ctor = (void*)fn_27_1DE10C;
