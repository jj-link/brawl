#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_1E82E8(void*, s32);
void fn_27_1E847C(void*, s32, void*);
int __register_global_object(void*, void (*)(void*), void*);
void fn_27_330E1C(void*);
}

struct soStaticObj {
    u8* m_vtbl;
    u32 m_pad;
    u8* m_data;
    u32 m_pad2;
};

extern "C" soStaticObj lbl_27_bss_7D90;
extern "C" u8 lbl_27_data_88FE0[0x18];
extern "C" u8 lbl_27_bss_7D84[0xC];

extern "C" void fn_27_330DA0() {
    soStaticObj* obj = &lbl_27_bss_7D90;
    fn_27_1E82E8(obj, 0);
    obj->m_data = lbl_27_data_88FE0;
    obj->m_vtbl = lbl_27_data_88FE0 + 8;
    fn_27_1E847C(obj, 0x73, obj);
    __register_global_object(obj, fn_27_330E1C, lbl_27_bss_7D84);
}

__declspec(section ".ctors") extern void* const fn_27_330DA0_ctor = (void*)fn_27_330DA0;
