#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_27_1E82E8(void*, int);
extern "C" void fn_27_1E847C(void*, int, void*);
extern "C" void fn_27_32433C();
extern "C" void __register_global_object(void*, void (*)(), void*);

extern "C" {
extern u32 lbl_27_bss_7C48[4];
extern u32 lbl_27_bss_7C3C[3];
extern u32 lbl_27_data_86930[6];
}

extern "C" void fn_27_3242C0() {
    fn_27_1E82E8(lbl_27_bss_7C48, 0);
    lbl_27_bss_7C48[2] = (u32)lbl_27_data_86930;
    lbl_27_bss_7C48[0] = (u32)lbl_27_data_86930 + 8;
    fn_27_1E847C(lbl_27_bss_7C48, 0x1f, lbl_27_bss_7C48);
    __register_global_object(lbl_27_bss_7C48, fn_27_32433C, lbl_27_bss_7C3C);
}

__declspec(section ".ctors") extern void* const fn_27_3242C0_ctor = (void*)fn_27_3242C0;
