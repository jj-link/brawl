#include <types.h>
#pragma force_active on

struct soTarget {
    s32 m_pad;
    s32 m_value;
};

class soInner2 {
public:
    virtual void vf0();
    virtual soTarget* vf1();
};

struct soOuter {
    u32 m_pad[4];
    soInner2 m_inner;
};

extern "C" {
s32 fn_27_10E778(soOuter* p) {
    return p->m_inner.vf1()->m_value;
}
}
