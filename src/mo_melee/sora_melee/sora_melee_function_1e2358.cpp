#include <types.h>
#pragma force_active on

extern "C" {
    extern u32 lbl_27_bss_5188[3];
    extern u32 lbl_27_bss_517C[3];
    extern u32 lbl_27_data_466C8[6];
    void fn_27_1E82E8(void* p, u32 flag);
    void fn_27_1E847C(void* p, u32 a, void* q);
    void fn_27_1E23D4(void* p);
    void __register_global_object(void* obj, void* dtor, void* handle);
}

extern "C" void fn_27_1E2358() {
    u32* obj = lbl_27_bss_5188;
    fn_27_1E82E8(obj, 0);
    obj[2] = (u32)lbl_27_data_466C8;
    obj[0] = (u32)lbl_27_data_466C8 + 8;
    fn_27_1E847C(obj, 0x85, obj);
    __register_global_object(obj, (void*)fn_27_1E23D4, lbl_27_bss_517C);
}

__declspec(section ".ctors") extern void* const fn_27_1E2358_ctor = (void*)fn_27_1E2358;
