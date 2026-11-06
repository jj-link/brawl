#pragma force_active on
extern "C" {
struct GlobalBase {
    void* vtbl;
};
extern char lbl_27_data_9AF88[0x40];
extern char lbl_27_bss_8910[0xC];
extern GlobalBase lbl_27_bss_891C;
void* fn_27_3980A0(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_3980E0() {
    lbl_27_bss_891C.vtbl = 0;
    lbl_27_bss_891C.vtbl = lbl_27_data_9AF88;
    __register_global_object(&lbl_27_bss_891C, (void*)fn_27_3980A0, lbl_27_bss_8910);
}
}

__declspec(section ".ctors") extern void* const fn_27_3980E0_ctor = (void*)fn_27_3980E0;
