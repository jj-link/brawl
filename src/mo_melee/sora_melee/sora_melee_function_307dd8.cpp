#pragma force_active on

struct GlobalObject {
    void* vtable;
};

extern "C" {
extern unsigned char lbl_27_data_82950[0x40];
extern void fn_27_307D98(void*, int);
extern GlobalObject lbl_27_bss_7704;
extern unsigned char lbl_27_bss_76F8[0xC];
extern void __register_global_object(void*, void*, void*);
}

extern "C" void fn_27_307DD8(void) {
    lbl_27_bss_7704.vtable = 0;
    lbl_27_bss_7704.vtable = &lbl_27_data_82950;
    __register_global_object(&lbl_27_bss_7704, &fn_27_307D98, &lbl_27_bss_76F8);
}

__declspec(section ".ctors") extern void* const fn_27_307DD8_ctor = (void*)fn_27_307DD8;
