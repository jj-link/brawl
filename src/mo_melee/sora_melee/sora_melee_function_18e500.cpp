#pragma force_active on

extern "C" {
struct GlobalBase27 {
    void* vtbl;
};
extern GlobalBase27 lbl_27_bss_4ECC;
extern char lbl_27_data_31D18[];
extern char lbl_27_bss_4EC0[];
void fn_27_18E4C0(void*, int);
void __register_global_object(void*, void*, void*);
void fn_27_18E500();
}

void fn_27_18E500() {
    lbl_27_bss_4ECC.vtbl = 0;
    lbl_27_bss_4ECC.vtbl = lbl_27_data_31D18;
    __register_global_object(&lbl_27_bss_4ECC, (void*)fn_27_18E4C0, lbl_27_bss_4EC0);
}

__declspec(section ".ctors") extern void* const fn_27_18E500_ctor = (void*)fn_27_18E500;
