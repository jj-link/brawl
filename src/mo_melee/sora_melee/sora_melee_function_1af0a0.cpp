#include <types.h>
#pragma force_active on

class soKineticEnergy;

struct Attr {
    s16 v;
    Attr() {}
    Attr(const Attr& o) : v(o.v) {}
};

template <class T>
class soInstanceUnitFullProperty {
public:
    Attr getAttribute() const;
};

class Inner {
public:
    virtual void v0();
    virtual void* get(s32 index);
    virtual void v2();
    virtual s32 count();
};

class Visitor {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void apply(void** p);
};

class Outer {
public:
    virtual void v0();
    u8 m_pad[0xC];
    Inner m_inner;
};

extern "C" {
void fn_27_1AF0A0(Outer* self, s16* mask, Visitor* visitor) {
    s32 n = self->m_inner.count();
    for (s32 i = 0; i < n; i++) {
        void* item = self->m_inner.get(i);
        Attr a = ((soInstanceUnitFullProperty<soKineticEnergy*>*)item)->getAttribute();
        if (a.v & *mask) {
            void* p = self->m_inner.get(i);
            visitor->apply(&p);
        }
    }
}
}
