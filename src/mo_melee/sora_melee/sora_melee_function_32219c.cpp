#pragma force_active on
struct SomeObj {
    void* m0;
    int m4;
    void* m8;
};

extern "C" void fn_27_1E82E8(SomeObj*, int);
extern "C" void fn_27_1E847C(SomeObj*, int, SomeObj*);
extern "C" void fn_27_322218(void*);
extern "C" int __register_global_object(void*, void*, void*);

extern "C" char lbl_27_data_862F0[];
extern "C" char lbl_27_bss_7BFC[];
extern SomeObj lbl_27_bss_7C08;

extern "C" void fn_27_32219C() {
    SomeObj* p = &lbl_27_bss_7C08;
    fn_27_1E82E8(p, 0);
    p->m8 = lbl_27_data_862F0;
    lbl_27_bss_7C08.m0 = lbl_27_data_862F0 + 8;
    fn_27_1E847C(p, 0x1e, p);
    __register_global_object(p, (void*)fn_27_322218, lbl_27_bss_7BFC);
}

__declspec(section ".ctors") extern void* const fn_27_32219C_ctor = (void*)fn_27_32219C;
