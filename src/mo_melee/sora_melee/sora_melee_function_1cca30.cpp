#include <types.h>
#pragma force_active on

struct Result {
    s32 pad;
    s32 field;
};

struct Inner {
    virtual Result* vf0();
    virtual Result* vf1();
};

struct Outer {
    u8 pad[0x10];
    Inner m_inner;
};

extern "C" s32 fn_27_1CCA30(Outer* p) {
    return p->m_inner.vf1()->field;
}
