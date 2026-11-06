#pragma force_active on
extern "C" {
struct GlobalObject {
    void* vtable;
};
extern GlobalObject lbl_27_bss_4DAC;
extern char lbl_27_data_312A0[];
extern char lbl_27_bss_4DA0[0xC];
void fn_27_187B50(void*, int);
void __register_global_object(void*, void*, void*);

void fn_27_187B90() {
    lbl_27_bss_4DAC.vtable = 0;
    lbl_27_bss_4DAC.vtable = (void*)&lbl_27_data_312A0;
    __register_global_object(&lbl_27_bss_4DAC, (void*)fn_27_187B50, lbl_27_bss_4DA0);
}
}

__declspec(section ".ctors") extern void* const fn_27_187B90_ctor = (void*)fn_27_187B90;
