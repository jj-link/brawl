#include <types.h>
#pragma force_active on

struct Obj {
    u8 pad[0x28];
    s32 unk28;
};

struct Inner {
    virtual void f0();
    virtual Obj* f1();
};

struct Outer {
    u8 pad[0x90];
    Inner* m_inner;
};

extern "C" {
void fn_27_1FA20(Obj* obj);

void fn_27_17AD0(Outer* self) {
    Obj* obj = self->m_inner->f1();
    fn_27_1FA20(obj);
    obj->unk28 = -1;
}
}
