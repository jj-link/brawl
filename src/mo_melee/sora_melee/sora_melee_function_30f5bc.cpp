#pragma force_active on
struct SoObj {
    void* a;
    void* b;
    void* c;
};

extern "C" void fn_27_1E82E8(SoObj*, int);
extern "C" void fn_27_1E847C(SoObj*, int, SoObj*);
extern "C" void fn_27_30F638(SoObj*);
extern "C" void __register_global_object(SoObj*, void (*)(SoObj*), void*);

extern "C" SoObj lbl_27_bss_7768;
extern "C" char lbl_27_bss_775C[];
extern "C" char lbl_27_data_836D0[];

extern "C" void fn_27_30F5BC() {
    fn_27_1E82E8(&lbl_27_bss_7768, 0);
    lbl_27_bss_7768.c = lbl_27_data_836D0;
    lbl_27_bss_7768.a = lbl_27_data_836D0 + 8;
    fn_27_1E847C(&lbl_27_bss_7768, 0x96, &lbl_27_bss_7768);
    __register_global_object(&lbl_27_bss_7768, fn_27_30F638, lbl_27_bss_775C);
}

__declspec(section ".ctors") extern void* const fn_27_30F5BC_ctor = (void*)fn_27_30F5BC;
