#include <types.h>
#pragma force_active on

class soKineticEnergy;

struct Attr {
    s16 v;
    Attr(const Attr&);
};

template <class T>
class soInstanceUnitFullProperty {
public:
    Attr getAttribute() const;
};

class Container {
public:
    virtual void s0();
    virtual void* getItem(s32 index);
    virtual void s2();
    virtual s32 getCount();
};

class Visitor {
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

class Owner {
public:
    u8 pad[0x10];
    Container mem;
};

extern "C" void fn_27_1ADCD0(Owner* self, s16* mask, Visitor* visitor) {
    s16 v;
    void* p;
    s32 n = self->mem.getCount();
    for (s32 i = 0; i < n; i++) {
        v = ((soInstanceUnitFullProperty<soKineticEnergy*>*)self->mem.getItem(i))->getAttribute().v;
        if (v & *mask) {
            p = self->mem.getItem(i);
            visitor->apply(&p);
        }
    }
}
