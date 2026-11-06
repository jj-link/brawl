#pragma force_active on

extern "C" {
struct GlobalObject {
    void* vtable;
};
extern GlobalObject lbl_27_bss_4FEC;
extern char lbl_27_data_32790[];
extern char lbl_27_bss_4FE0[];
void fn_27_1924C0(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_192500() {
    lbl_27_bss_4FEC.vtable = 0;
    lbl_27_bss_4FEC.vtable = &lbl_27_data_32790;
    __register_global_object(&lbl_27_bss_4FEC, (void*)fn_27_1924C0, lbl_27_bss_4FE0);
}
}

__declspec(section ".ctors") extern void* const fn_27_192500_ctor = (void*)fn_27_192500;
