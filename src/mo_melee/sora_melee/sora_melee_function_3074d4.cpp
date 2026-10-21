#pragma force_active on
struct Obj {
    void* vtbl;
    int x;
    void* ptr;
};

extern "C" void fn_27_1E82E8(Obj*, int);
extern "C" void fn_27_1E847C(Obj*, int, Obj*);
extern "C" void fn_27_307550(Obj*);
extern "C" void __register_global_object(Obj*, void (*)(Obj*), void*);
extern "C" char lbl_27_data_826B0[];
extern "C" char lbl_27_bss_76D4[];
extern "C" Obj lbl_27_bss_76E0;

extern "C" void fn_27_3074D4() {
    fn_27_1E82E8(&lbl_27_bss_76E0, 0);
    lbl_27_bss_76E0.ptr = lbl_27_data_826B0;
    lbl_27_bss_76E0.vtbl = lbl_27_data_826B0 + 8;
    fn_27_1E847C(&lbl_27_bss_76E0, 0x40, &lbl_27_bss_76E0);
    __register_global_object(&lbl_27_bss_76E0, fn_27_307550, lbl_27_bss_76D4);
}

__declspec(section ".ctors") extern void* const fn_27_3074D4_ctor = (void*)fn_27_3074D4;
