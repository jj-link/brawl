#include <types.h>
#pragma force_active on

class soVirtBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};

extern "C" {
void fn_27_5A24C(soVirtBase* self) {
    self->v4();
    self->v6();
}
}
