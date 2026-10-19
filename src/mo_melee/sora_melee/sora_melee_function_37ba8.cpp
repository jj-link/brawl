#include <types.h>
#pragma force_active on

extern "C" {
u32 fn_27_38048(u32);
}

class SoraInner {
public:
    virtual u32 vf0();
    virtual u32 vf1();
    virtual u32 vf2();
    virtual u32 vf3();
};

struct SoraOuter {
    u8 pad[8];
    SoraInner* m_inner;
};

extern "C" u32 fn_27_37BA8(SoraOuter* p) {
    return fn_27_38048(p->m_inner->vf1());
}
