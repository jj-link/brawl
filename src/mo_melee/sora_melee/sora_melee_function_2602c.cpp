#include <types.h>
#pragma force_active on

struct FnBar {
    u8 _0[2];
    u16 m_x;
};

struct FnFoo {
    u8 _0[0x2c];
    void* m_a;
    FnBar* m_b;
};

extern "C" u16 fn_27_2602C(FnFoo* p) {
    if (p->m_a == 0 || p->m_b == 0) {
        return 0;
    }
    return p->m_b->m_x;
}
