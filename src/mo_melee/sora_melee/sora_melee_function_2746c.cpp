#include <types.h>
#pragma force_active on

struct Ret {
    u32 unk0;
    void* unk4;
};

struct Sub {
    virtual void f0();
    virtual Ret* f1();
};

struct Outer {
    u8 pad[0x28];
    Sub* m_28;
};

extern "C" {
void* fn_27_2746C(const Outer* self) {
    return self->m_28->f1()->unk4;
}
}
