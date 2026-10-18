#include <types.h>
#pragma force_active on

struct Inner {
    virtual void* pad();
    virtual void* get();
};

struct Outer {
    u32 pad[2];
    Inner* inner;
};

extern "C" void fn_27_37960(Outer* self, float value) {
    void* result = self->inner->get();
    *(float*)((u8*)result + 0x4C) = value;
}
