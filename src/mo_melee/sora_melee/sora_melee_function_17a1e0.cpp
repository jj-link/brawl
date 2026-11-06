#pragma force_active on
extern "C" {
extern unsigned char lbl_27_data_30160[0x40];
extern unsigned char lbl_27_bss_4B50[12];

struct GlobalObj {
    void* vtbl;
};
extern GlobalObj lbl_27_bss_4B5C;

void* fn_27_17A1A0(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_17A1E0() {
    lbl_27_bss_4B5C.vtbl = 0;
    lbl_27_bss_4B5C.vtbl = (void*)lbl_27_data_30160;
    __register_global_object(&lbl_27_bss_4B5C, (void*)fn_27_17A1A0, (void*)lbl_27_bss_4B50);
}
}

__declspec(section ".ctors") extern void* const fn_27_17A1E0_ctor = (void*)fn_27_17A1E0;
