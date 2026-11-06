#pragma force_active on

extern "C" {
extern char lbl_27_data_31600[0x40];
extern unsigned char lbl_27_bss_4E10[0xC];
struct GlobalObj {
    void* vtable;
};
extern GlobalObj lbl_27_bss_4E1C;
void fn_27_18A63C(void*, int);
void* __register_global_object(void*, void*, void*);

void fn_27_18A6BC() {
    lbl_27_bss_4E1C.vtable = 0;
    lbl_27_bss_4E1C.vtable = &lbl_27_data_31600;
    __register_global_object(&lbl_27_bss_4E1C, (void*)fn_27_18A63C, lbl_27_bss_4E10);
}
}

__declspec(section ".ctors") extern void* const fn_27_18A6BC_ctor = (void*)fn_27_18A6BC;
