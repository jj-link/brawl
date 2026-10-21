#include <types.h>
#pragma force_active on

class soKineticEnergy;

struct AttrVal {
    s16 v;
    AttrVal();
    AttrVal(const AttrVal& o);
};

template <class T>
class soInstanceUnitFullProperty {
public:
    AttrVal getAttribute() const;
};

class Inner {
public:
    virtual void v0();
    virtual void* get(s32 idx);
    virtual void v2();
    virtual s32 count();
};

class Outer {
public:
    virtual void v0();
    u8 pad[0xC];
    Inner inner;
};

class Sink {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void apply(void** p);
};

extern "C" {
void fn_27_2EA9A0(Outer* self, s16* mask, Sink* sink) {
    s32 n = self->inner.count();
    for (s32 i = 0; i < n; i++) {
        AttrVal a = ((soInstanceUnitFullProperty<soKineticEnergy*>*)self->inner.get(i))->getAttribute();
        if (a.v & *mask) {
            void* p = self->inner.get(i);
            sink->apply(&p);
        }
    }
}
}
