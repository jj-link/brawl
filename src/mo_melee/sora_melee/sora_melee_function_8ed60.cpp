#include <types.h>
#pragma force_active on

struct Inner {
    s32 unk0;
};

struct Base {
    virtual void f0();
    virtual Inner* f1(s16 x);
};

struct Outer {
    u8 pad[0xC];
    Base* m_base;
};

extern "C" s32 fn_27_8ED60(Outer* self, s16 x) {
    return self->m_base->f1(x)->unk0;
}
