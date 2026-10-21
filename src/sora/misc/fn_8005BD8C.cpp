#include <types.h>
#pragma force_active on

struct FnBar {
    u8 _0[0x18];
    u16 m_x;
};

struct FnFoo {
    u8 _0[0x30];
    FnBar* m_b;
};

extern "C" u16 fn_8005BD8C(FnFoo* p) {
    if (p->m_b == 0) {
        return 0;
    }
    return p->m_b->m_x;
}
