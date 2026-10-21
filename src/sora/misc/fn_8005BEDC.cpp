#include <types.h>
#pragma force_active on

struct FnInner {
    u8 _0[0x18];
    u16 m_x;
};

struct FnOuter {
    u8 _0[0x24];
    FnInner* m_inner;
};

extern "C" {
u16 fn_8005BEDC(FnOuter* p) {
    if (p->m_inner == 0) {
        return 0;
    }
    return p->m_inner->m_x;
}
}
