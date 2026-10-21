#pragma force_active on
struct SoObj {
    void* vt;
    int a;
    void* p;
    int b;
};

extern "C" void fn_27_1E82E8(SoObj*, int);
extern "C" void fn_27_1E847C(SoObj*, int, SoObj*);
extern "C" void fn_27_3C9A80(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);

extern unsigned char lbl_27_data_A36B8[0x18];
extern unsigned char lbl_27_bss_8C7C[0xC];
extern SoObj lbl_27_bss_8C88;

extern "C" {
void fn_27_3C9A04() {
    fn_27_1E82E8(&lbl_27_bss_8C88, 0);
    lbl_27_bss_8C88.p = lbl_27_data_A36B8;
    lbl_27_bss_8C88.vt = lbl_27_data_A36B8 + 8;
    fn_27_1E847C(&lbl_27_bss_8C88, 0x26, &lbl_27_bss_8C88);
    __register_global_object(&lbl_27_bss_8C88, fn_27_3C9A80, lbl_27_bss_8C7C);
}
}

__declspec(section ".ctors") extern void* const fn_27_3C9A04_ctor = (void*)fn_27_3C9A04;
