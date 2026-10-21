#pragma force_active on
extern "C" {
struct SoObj {
    void* vt;
    unsigned char flag;
};
extern void* __register_global_object(void* object, void* destructor, void* chain);
extern void* fn_27_2BCE28(void* p, int n);
extern void* __vt__10soNullable[];
extern void* lbl_27_data_7A1D8[];
extern unsigned char lbl_27_bss_7178[];
extern SoObj lbl_27_bss_7188;

void* fn_27_2BDF04() {
    lbl_27_bss_7188.vt = __vt__10soNullable;
    lbl_27_bss_7188.flag = 0;
    lbl_27_bss_7188.vt = lbl_27_data_7A1D8;
    return __register_global_object(&lbl_27_bss_7188, (void*)fn_27_2BCE28, lbl_27_bss_7178);
}
}

__declspec(section ".ctors") extern void* const fn_27_2BDF04_ctor = (void*)fn_27_2BDF04;
