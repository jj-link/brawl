#include <types.h>
#pragma force_active on

class fnInner {
public:
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10(s16 v);
};

class fnOuter {
public:
    u32 m_0;
    u32 m_4;
    fnInner* m_8;
};

extern "C" {
void fn_27_DA144(fnOuter* o, s16 v) {
    o->m_8->vf10(v);
}
}
