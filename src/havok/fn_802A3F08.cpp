#include <types.h>
#pragma force_active on

class Obj {
public:
    virtual ~Obj();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(s32);
};

struct Element {
    u32 pad0;
    u32 pad4;
    Obj* obj;
};

struct Owner {
    u8 pad0[0xc];
    Element* m_elements;
    s32 m_count;
};

extern "C" void fn_802A3F08(Owner* self, s32 arg1) {
    Element* base = self->m_elements;
    Element* end = base + self->m_count;
    while (base != end) {
        Obj* obj = base->obj;
        if (obj != 0) {
            obj->v8(arg1);
        }
        base++;
    }
}
