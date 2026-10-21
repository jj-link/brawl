#include <types.h>
#pragma force_active on

extern "C" void* __vt__10soNullable[];
extern "C" unsigned char lbl_27_data_6E94[];
extern "C" unsigned char lbl_27_data_2D880[];
extern "C" void* fn_27_1516D8(void* p, s32 n);
extern "C" void* __register_global_object(void* object, void* destructor, void* chain);

struct soNullableObj {
    void* vtable;
    bool flag;
    void* ptr;
};

extern "C" soNullableObj lbl_27_bss_4694;
extern "C" unsigned char lbl_27_bss_4688[];

extern "C" {
void fn_27_151718() {
    lbl_27_bss_4694.vtable = __vt__10soNullable;
    lbl_27_bss_4694.ptr = lbl_27_data_6E94;
    lbl_27_bss_4694.vtable = lbl_27_data_6E94 + 8;
    lbl_27_bss_4694.flag = false;
    lbl_27_bss_4694.ptr = lbl_27_data_2D880;
    lbl_27_bss_4694.vtable = lbl_27_data_2D880 + 8;
    __register_global_object(&lbl_27_bss_4694, reinterpret_cast<void*>(fn_27_1516D8), lbl_27_bss_4688);
}
}

__declspec(section ".ctors") extern void* const fn_27_151718_ctor = (void*)fn_27_151718;
