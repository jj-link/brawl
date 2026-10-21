#include <types.h>
#pragma force_active on

extern "C" void fn_27_1E82E8(void* p, s32 a);
extern "C" void fn_27_1E847C(void* p, s32 a, void* q);
extern "C" void __register_global_object(void* p, void* f, void* q);
extern "C" void fn_27_353EB8(void* p);

struct Obj {
    void* f0;
    void* f1;
    void* f2;
    void* f3;
};

extern "C" Obj lbl_27_bss_7FC0;
extern "C" char lbl_27_data_8EAC8[];
extern "C" char lbl_27_bss_7FB4[];

extern "C" void fn_27_353E3C() {
    fn_27_1E82E8(&lbl_27_bss_7FC0, 0);
    lbl_27_bss_7FC0.f2 = lbl_27_data_8EAC8;
    lbl_27_bss_7FC0.f0 = lbl_27_data_8EAC8 + 8;
    fn_27_1E847C(&lbl_27_bss_7FC0, 0x23, &lbl_27_bss_7FC0);
    __register_global_object(&lbl_27_bss_7FC0, (void*)fn_27_353EB8, lbl_27_bss_7FB4);
}

__declspec(section ".ctors") extern void* const fn_27_353E3C_ctor = (void*)fn_27_353E3C;
