#include <types.h>
#pragma force_active on

struct Ret {
    s32 a;
    s32 b;
};

class Inner {
public:
    virtual void f0();
    virtual Ret* get();
};

struct Outer {
    u8 pad[0x10];
    Inner m_inner;
};

extern "C" s32 fn_27_1E5AC0(Outer* self) {
    return self->m_inner.get()->b;
}
