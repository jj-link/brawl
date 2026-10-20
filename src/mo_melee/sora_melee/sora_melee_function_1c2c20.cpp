#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void v01() { }
    virtual void v02() { }
    virtual void v03() { }
    virtual void v04() { }
    virtual void v05() { }
    virtual void v06() { }
    virtual void v07() { }
    virtual void v08() { }
    virtual void v09() { }
    virtual void v10() { }
    virtual void v11() { }
    virtual void v12() { }
    virtual void v13() { }
    virtual void target();
};

struct Outer {
    char pad[0x10];
    Inner m;
};

extern "C" {
void fn_27_1C2C20(Outer* self) {
    self->m.target();
}
}
