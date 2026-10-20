#include <types.h>
#pragma force_active on

class Vt {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v9(u32 a, u32 b, u32 c);
};

struct Mid {
    char pad[0x40];
    Vt* vt;
};

struct Outer {
    char pad[0xd8];
    Mid* mid;
};

extern "C" void fn_27_135EB4(void* unused, Outer* self, u32 a, u32 b, u32 c) {
    self->mid->vt->v9(a, b, c);
}
