#include <types.h>
#pragma force_active on

extern u8 lbl_27_data_3C578[];

extern "C" void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern "C" void fn_27_D2A0C(void* p);
extern "C" void* fn_27_AB510(void* p, s32 n);

struct fnS27_1A1B1C {
    void* m_00;
    void* m_04;
    u32 m_08;
};

extern "C" fnS27_1A1B1C* fn_27_1A1B1C(fnS27_1A1B1C* p) {
    p->m_00 = lbl_27_data_3C578;
    p->m_04 = lbl_27_data_3C578 + 0x48;
    p->m_08 = p->m_08 & 0x3FFFFF;
    __construct_array((char*)p + 0xc, (void (*)(void*))fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 2);
    return p;
}
