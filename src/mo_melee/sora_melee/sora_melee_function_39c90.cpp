#include <types.h>
#pragma force_active on

struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual s32 getCount();
};

struct Outer {
    u8 pad0[0x64];
    Inner* m_inner;
    u8 m_sub[0x9C - 0x68];
    u32 m_flags;
};

extern "C" {
void fn_27_37A14(void* p, u32 index);

void fn_27_39C90(Outer* self) {
    s32 count = self->m_inner->getCount();
    for (s32 i = 0; i < count; i++) {
        fn_27_37A14(self->m_sub, i);
    }
    self->m_flags |= 0x20000000;
    self->m_flags &= ~0x08000000;
}
}
