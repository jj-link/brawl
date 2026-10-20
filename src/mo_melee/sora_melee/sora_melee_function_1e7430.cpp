#include <types.h>
#pragma force_active on

class BaseA {
    char _0[16];
};

class BaseB {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void target();
};

class Self : public BaseA, public BaseB {
};

extern "C" void fn_27_1E7430(Self* self) {
    self->target();
}
