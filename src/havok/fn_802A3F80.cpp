#include <types.h>
#pragma force_active on

class Child {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9(s32, f32, f32) = 0;
};

struct Element {
    u32 pad0;
    u32 pad4;
    Child* ptr;
};

struct Owner {
    u8 pad0[0xc];
    Element* m_elements;
    s32 m_count;
};

extern "C" void fn_802A3F80(Owner* self, s32 arg1, f32 farg0, f32 farg1) {
    Element* base = self->m_elements;
    Element* end = base + self->m_count;
    while (base != end) {
        Child* child = base->ptr;
        if (child != 0) {
            child->v9(arg1, farg0, farg1);
        }
        base++;
    }
}
