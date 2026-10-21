#pragma force_active on
extern "C" void fn_27_1E82E8(void*, int);
extern "C" void fn_27_1E847C(void*, int, void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void fn_27_2DDCE4(void*);

struct soStaticObj {
    void* vtbl;
    int field;
    void* ptr;
};

extern "C" soStaticObj lbl_27_bss_7368;
extern "C" char lbl_27_bss_735C[];
extern "C" char lbl_27_data_7C030[];

extern "C" void fn_27_2DDC68() {
    fn_27_1E82E8(&lbl_27_bss_7368, 0);
    lbl_27_bss_7368.ptr = lbl_27_data_7C030;
    lbl_27_bss_7368.vtbl = lbl_27_data_7C030 + 8;
    fn_27_1E847C(&lbl_27_bss_7368, 0, &lbl_27_bss_7368);
    __register_global_object(&lbl_27_bss_7368, fn_27_2DDCE4, lbl_27_bss_735C);
}

__declspec(section ".ctors") extern void* const fn_27_2DDC68_ctor = (void*)fn_27_2DDC68;
