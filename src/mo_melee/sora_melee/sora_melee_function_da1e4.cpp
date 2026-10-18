#include <types.h>
#pragma force_active on

class fnInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(s16 v);
};

class fnOuter {
public:
    u8 pad[8];
    fnInner* m_inner;
};

extern "C" void fn_27_DA1E4(fnOuter* p, s16 v) {
    p->m_inner->vf8(v);
}
