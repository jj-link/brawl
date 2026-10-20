#include <types.h>
#pragma force_active on

class soInner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13(u32 a, u32 b, u32 c);
};

class soMid {
public:
    u8 pad[0x24];
    soInner* m_inner;
};

class soOuter {
public:
    u8 pad[0xd8];
    soMid* m_mid;
};

extern "C" {
void fn_27_16A838(void*, soOuter* obj) {
    obj->m_mid->m_inner->vf13(0, 1, 0);
}
}
