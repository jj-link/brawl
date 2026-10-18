#include <types.h>
#pragma force_active on

struct Target {
    u32 value;
};

struct Inner {
    virtual void v0();
    virtual Target* getTarget();
};

struct Outer {
    char pad[0x30];
    Inner* inner;
};

extern "C" void fn_27_75B2C(Outer* self, u32 unused, u32 val) {
    Target* t = self->inner->getTarget();
    t->value = val;
}
