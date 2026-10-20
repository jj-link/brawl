#include <types.h>
#pragma force_active on

class W {
public:
    virtual s32 a(u32) const;
    virtual s32 c(u32) const;
    virtual void b(s32, u32);
};

struct Foo {
    u8 pad[0x7f64];
    W m;
};

extern "C" void fn_27_384E4C(Foo* self, s32 value, u32 index) {
    self->m.b(value, index);
}
