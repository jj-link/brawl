#include <types.h>
#pragma force_active on

struct FnInner {
    u8 _0[0xc];
    u16 m_x;
};

struct FnOuter {
    u8 _0[0x18];
    FnInner* m_p;
};

extern "C" u16 fn_8005C010(FnOuter* p) {
    if (p->m_p == 0) {
        return 0;
    }
    return p->m_p->m_x;
}
