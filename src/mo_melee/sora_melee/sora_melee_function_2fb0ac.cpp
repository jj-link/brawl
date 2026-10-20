#include <types.h>
#pragma force_active on

class Base {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual u32 get6(u32 arg) = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void set22(u32 arg) = 0;
};

struct X {
    char pad0[0x64];
    Base* y;
    char pad1[0x88 - 0x68];
    Base* z;
};

struct Obj {
    char pad0[0xd8];
    X* x;
};

extern "C" {
void fn_27_2FB0AC(void* unused, Obj* self) {
    u32 r = self->x->y->get6(0x10000040);
    if (r) {
        self->x->z->set22(r);
    }
}
}
