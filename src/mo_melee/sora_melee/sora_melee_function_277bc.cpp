#include <types.h>
#pragma force_active on

struct B {
    u8 pad[8];
    u32 val;
};

struct Ret {
    u8 pad[4];
    B* b;
};

extern "C" void fn_801345E0(B* b, float f, s32 s);

class Obj {
public:
    virtual void v0();
    virtual Ret* v3(float f);
};

struct Self {
    u8 pad[0x28];
    Obj* o;
};

extern "C" void fn_27_277BC(Self* self, float f) {
    Ret* r = self->o->v3(f);
    u32 v = r->b->val;
    u32 x = (v >> 8) | (v << 24);
    x &= 0xFF800000;
    s32 s = (s32)x >> 24;
    fn_801345E0(r->b, f, s);
}
