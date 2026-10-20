#include <types.h>
#pragma force_active on

struct Src;
struct Obj;
struct Desc;

extern "C" void fn_27_41EFC(Src* src, Obj* obj, Desc* desc);

struct Inner {
    virtual void f0();
    virtual Src* f1(Desc* desc);
};

struct Owner {
    u8 pad0[0x30];
    Obj* m_obj;
    u8 pad1[0x58 - 0x34];
    Inner* m_inner;
};

extern "C" void fn_27_436CC(Owner* self, Desc* a, Desc* b) {
    Src* src = self->m_inner->f1(b);
    fn_27_41EFC(src, self->m_obj, a);
}
