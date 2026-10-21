#include <types.h>
#pragma force_active on

struct Inner {
    char pad[0x10];
    s32 offset;
    char pad2[4];
    s8 type;
};

struct Outer {
    s32 pad0;
    Inner* inner;
};

class Target {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11(void* p);
};

extern "C" void fn_802E9690(Target* t, Outer* o) {
    Inner* in = o->inner;
    void* p;
    if (in->type == 1) {
        p = (char*)in + in->offset;
    } else {
        p = 0;
    }
    if (p == 0) {
        return;
    }
    t->vf11(p);
}
