#pragma force_active on
struct GlobalObject { void* vtable; };
extern "C" {
extern char lbl_27_data_2FFF8[0x40];
extern GlobalObject lbl_27_bss_4B2C;
extern char lbl_27_bss_4B20[0xC];
extern void* fn_27_1790C0(void*, int);
extern void __register_global_object(void*, void*, void*);
}
extern "C" void fn_27_179100() {
    lbl_27_bss_4B2C.vtable = 0;
    lbl_27_bss_4B2C.vtable = &lbl_27_data_2FFF8[0];
    __register_global_object(&lbl_27_bss_4B2C, fn_27_1790C0, lbl_27_bss_4B20);
}

__declspec(section ".ctors") extern void* const fn_27_179100_ctor = (void*)fn_27_179100;
