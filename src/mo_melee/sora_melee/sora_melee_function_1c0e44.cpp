#include <types.h>
#pragma force_active on

class soNode {
public:
    u32 m_head;
    void* m_field;
};

class soInner {
public:
    virtual void v0();
    virtual soNode* v1();
};

class soOuter {
public:
    u32 m_pad[4];
    soInner m_inner;
};

extern "C" void* fn_27_1C0E44(soOuter* o) {
    soInner* p = &o->m_inner;
    return p->v1()->m_field;
}
