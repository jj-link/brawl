#include <types.h>
#pragma force_active on

extern "C" void fn_27_1E82E8(void*, int);
extern "C" void fn_27_1E847C(void*, int, void*);
extern "C" void fn_27_3A04FC(void*);
extern "C" int __register_global_object(void*, void (*)(void*), void*);

extern "C" u8 lbl_27_data_9BE20[0x18];
extern "C" u8 lbl_27_bss_899C[0xC];

struct soGlobalObj {
    u8* m_vt;
    u32 m_pad;
    u8* m_ptr;
};

extern "C" soGlobalObj lbl_27_bss_89A8;

extern "C" void fn_27_3A0480() {
    fn_27_1E82E8(&lbl_27_bss_89A8, 0);
    lbl_27_bss_89A8.m_ptr = lbl_27_data_9BE20;
    lbl_27_bss_89A8.m_vt = lbl_27_data_9BE20 + 8;
    fn_27_1E847C(&lbl_27_bss_89A8, 0x63, &lbl_27_bss_89A8);
    __register_global_object(&lbl_27_bss_89A8, fn_27_3A04FC, lbl_27_bss_899C);
}

__declspec(section ".ctors") extern void* const fn_27_3A0480_ctor = (void*)fn_27_3A0480;
