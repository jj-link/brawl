#pragma force_active on
extern "C" {
struct GlobalBase {
    void* vtbl;
};
extern char lbl_27_data_31CA8[];
extern char lbl_27_bss_4EB0[];
extern GlobalBase lbl_27_bss_4EBC;
void fn_27_18DEEC(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_18DF2C() {
    lbl_27_bss_4EBC.vtbl = 0;
    lbl_27_bss_4EBC.vtbl = lbl_27_data_31CA8;
    __register_global_object(&lbl_27_bss_4EBC, fn_27_18DEEC, lbl_27_bss_4EB0);
}
}

__declspec(section ".ctors") extern void* const fn_27_18DF2C_ctor = (void*)fn_27_18DF2C;
