#include <types.h>
#pragma force_active on

struct Data {
    s32 m_a;
    s32 m_b;
};

struct Inner {
    virtual void f0();
    virtual Data* getData();
};

struct Outer {
    u32 m_pad[4];
    Inner m_inner;
};

extern "C" s32 fn_27_2BB930(Outer* p) {
    Inner* ip = &p->m_inner;
    return ip->getData()->m_b;
}
