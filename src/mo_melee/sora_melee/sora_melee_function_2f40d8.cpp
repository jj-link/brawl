#pragma force_active on

extern "C" {
struct GlobalBase {
    void* vtbl;
};

extern GlobalBase lbl_27_bss_7564;
extern char lbl_27_bss_7558[0xC];
extern char lbl_27_data_7F790[];
void* fn_27_2F4098(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_2F40D8() {
    lbl_27_bss_7564.vtbl = 0;
    lbl_27_bss_7564.vtbl = lbl_27_data_7F790;
    __register_global_object(&lbl_27_bss_7564, fn_27_2F4098, lbl_27_bss_7558);
}
}

__declspec(section ".ctors") extern void* const fn_27_2F40D8_ctor = (void*)fn_27_2F40D8;
