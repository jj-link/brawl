#pragma force_active on
extern "C" {
struct GlobalBase {
    void* vtbl;
};
extern char lbl_27_data_30E68[];
extern char lbl_27_bss_4D20[0xC];
extern GlobalBase lbl_27_bss_4D2C;
void fn_27_186A30(void*, int);
void* __register_global_object(void*, void*, void*);
}
extern "C" void fn_27_186A70() {
    lbl_27_bss_4D2C.vtbl = 0;
    lbl_27_bss_4D2C.vtbl = &lbl_27_data_30E68;
    __register_global_object(&lbl_27_bss_4D2C, (void*)fn_27_186A30, lbl_27_bss_4D20);
}

__declspec(section ".ctors") extern void* const fn_27_186A70_ctor = (void*)fn_27_186A70;
