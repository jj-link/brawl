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
    virtual int vf6();
    virtual void vf7();
    virtual void vf8(int arg);
};

class fnOwner {
public:
    u32 m_pad[3];
    fnInner* m_inner;
};

extern "C" {
void fn_27_8EDF8(fnOwner* owner, int arg) {
    if (owner->m_inner->vf6()) {
        owner->m_inner->vf8(arg);
    }
}
}
