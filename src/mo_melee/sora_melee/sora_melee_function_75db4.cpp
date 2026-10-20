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
    virtual s32 vf7();
    virtual void vf8();
};

class fnOuter {
public:
    u8 pad[0x2c];
    fnInner* m_2c;
};

extern "C" s32 fn_27_75DB4(fnOuter* p1) {
    return p1->m_2c->vf7();
}
