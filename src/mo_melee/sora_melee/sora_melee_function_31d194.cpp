#pragma force_active on

extern "C" {
struct GlobalBase {
    void* vtbl;
};
extern GlobalBase lbl_27_bss_7BB4;
extern char lbl_27_data_85350[];
extern char lbl_27_bss_7BA8[12];
void fn_27_31D154(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_31D194() {
    lbl_27_bss_7BB4.vtbl = 0;
    lbl_27_bss_7BB4.vtbl = (void*)lbl_27_data_85350;
    __register_global_object(&lbl_27_bss_7BB4, (void*)fn_27_31D154, lbl_27_bss_7BA8);
}
}

__declspec(section ".ctors") extern void* const fn_27_31D194_ctor = (void*)fn_27_31D194;
