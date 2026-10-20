#include <types.h>
#pragma force_active on

struct fnS27D2A0C;

extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_27_D2A0C(fnS27D2A0C* p);
void* fn_27_AB510(void* p, s32 n);
extern u8 lbl_27_data_3C688[];
}

struct fnS27Thing {
    void* m_0;
    void* m_4;
    u32 m_8;
    u8 m_c[0x10];
};

extern "C" fnS27Thing* fn_27_1A154C(fnS27Thing* p) {
    p->m_0 = lbl_27_data_3C688;
    p->m_4 = lbl_27_data_3C688 + 0x48;
    p->m_8 = p->m_8 & 0x1FFFFFF;
    __construct_array(p->m_c, (void (*)(void*))fn_27_D2A0C, (void (*)(void*))fn_27_AB510, 0x10, 1);
    return p;
}
