#include <types.h>
#pragma force_active on

struct Ret {
    s32 pad;
    s32 field;
};

class Inner {
public:
    virtual void v0();
    virtual Ret* v3();
};

class Outer {
public:
    u8 pad[0x10];
    Inner m_inner;
};

extern "C" s32 fn_27_1C7B10(Outer* self) {
    return self->m_inner.v3()->field;
}
