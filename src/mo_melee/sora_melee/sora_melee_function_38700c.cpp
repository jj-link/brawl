#pragma force_active on

extern "C" {

struct GlobalBase {
    void* vtbl;
};

extern char lbl_27_data_990D8[];
extern char lbl_27_bss_8800[0xC];
extern GlobalBase lbl_27_bss_880C;
void* fn_27_386FCC(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_38700C() {
    lbl_27_bss_880C.vtbl = 0;
    lbl_27_bss_880C.vtbl = lbl_27_data_990D8;
    __register_global_object(&lbl_27_bss_880C, fn_27_386FCC, lbl_27_bss_8800);
}

}

__declspec(section ".ctors") extern void* const fn_27_38700C_ctor = (void*)fn_27_38700C;
