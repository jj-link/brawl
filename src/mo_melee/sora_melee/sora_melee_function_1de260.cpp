#pragma force_active on
struct GlobalObject {
    void* vtable;
};
extern GlobalObject lbl_27_bss_512C;

extern "C" {
extern char lbl_27_data_45E00[0x40];
extern char lbl_27_bss_5120[0xC];
void fn_27_1DE220(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_1DE260() {
    lbl_27_bss_512C.vtable = 0;
    lbl_27_bss_512C.vtable = (void*)&lbl_27_data_45E00;
    __register_global_object(&lbl_27_bss_512C, (void*)fn_27_1DE220, lbl_27_bss_5120);
}
}

__declspec(section ".ctors") extern void* const fn_27_1DE260_ctor = (void*)fn_27_1DE260;
