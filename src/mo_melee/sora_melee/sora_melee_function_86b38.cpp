#include <types.h>
#pragma force_active on

struct Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual u32 isActive();
    virtual void v4();
    virtual void v5();
};

extern "C" bool fn_27_86B38(Base* self) {
    return self->isActive() == 0;
}
