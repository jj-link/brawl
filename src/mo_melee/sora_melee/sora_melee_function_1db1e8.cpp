#include <types.h>
#pragma force_active on

class A {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v7(u32 a, u32 b);
};
struct C { u8 pad[0x64]; A* a; };
struct B { u8 pad[0xD8]; C* c; };
struct Self { u8 pad[0x60]; B* b; };
struct P { u32 x; u32 y; };

extern "C" void fn_27_1DB1E8(Self* self, const P& p) {
    self->b->c->a->v7(p.x, 0x10000001);
    self->b->c->a->v7(p.y, 0x10000002);
}
