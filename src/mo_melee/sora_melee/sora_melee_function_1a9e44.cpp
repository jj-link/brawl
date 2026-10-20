#include <types.h>
#pragma force_active on

class soSub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

class soOuter {
public:
    u32 m_pad[3];
    soSub m_sub;
};

extern "C" {
void fn_27_1A9E44(soOuter* p) {
    p->m_sub.v4();
}
}
