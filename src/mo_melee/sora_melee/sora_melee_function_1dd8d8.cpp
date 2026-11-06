#pragma force_active on

extern "C" {
struct GlobalBase {
    void* vtbl;
};
extern GlobalBase lbl_27_bss_50DC;
extern char lbl_27_data_45BA8[0x40];
extern char lbl_27_bss_50D0[0xC];
void fn_27_1DD898(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_1DD8D8() {
    lbl_27_bss_50DC.vtbl = 0;
    lbl_27_bss_50DC.vtbl = (void*)lbl_27_data_45BA8;
    __register_global_object(&lbl_27_bss_50DC, (void*)fn_27_1DD898, lbl_27_bss_50D0);
}
}

__declspec(section ".ctors") extern void* const fn_27_1DD8D8_ctor = (void*)fn_27_1DD8D8;
