#include <types.h>
#pragma force_active on

struct Inner {
    virtual void f0();
    virtual Inner* f1(u32 v);
    u32 m_4;
};

struct Field34 {
    u32 hi : 9;
    u32 f : 10;
    u32 lo : 13;
};

struct Outer {
    u32 unk0;
    u32 unk4;
    u32 unk8[11];
    Field34 m_34;
    u32 unk38[3];
    Inner m_44;
};

extern "C" void fn_27_38994(Outer* self, u32 val) {
    self->m_34.f = val;
    Inner* p = self->m_44.f1(1);
    p->m_4 = val;
}
