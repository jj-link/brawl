#include <types.h>
#pragma force_active on

class soKineticEnergy;

class soAttr {
public:
    soAttr();
    soAttr(const soAttr& o);
    s16 v;
    s16 w;
};

template <class T>
class soInstanceUnitFullProperty {
public:
    soAttr getAttribute() const;
};

class soInner {
public:
    virtual void f2();
    virtual void* getItem(s32 index);
    virtual void f4();
    virtual s32 getCount();
};

class soOuter {
public:
    virtual void f0();
    u8 m_pad[0xC];
    soInner m_inner;
};

class soVisitor {
public:
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void visit(void** p);
};

extern "C" {
void fn_27_1AD2B4(soOuter* self, s16* mask, soVisitor* visitor) {
    s32 n = self->m_inner.getCount();
    for (s32 i = 0; i < n; i++) {
        void* p;
        soAttr a = ((soInstanceUnitFullProperty<soKineticEnergy*>*)self->m_inner.getItem(i))->getAttribute();
        if (a.v & *mask) {
            p = self->m_inner.getItem(i);
            visitor->visit(&p);
        }
    }
}
}
