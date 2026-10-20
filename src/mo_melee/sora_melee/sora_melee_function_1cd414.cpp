#include <types.h>
#pragma force_active on

struct Ret {
    s32 a;
    s32 b;
};

class Sub {
public:
    virtual void v0();
    virtual Ret* get();
};

class Outer {
public:
    u8 pad[0x10];
    Sub m_sub;
};

extern "C" {
s32 fn_27_1CD414(Outer* self) {
    return self->m_sub.get()->b;
}
}
