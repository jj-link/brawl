#include <types.h>
#pragma force_active on

struct Cls {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool isEnable();
};

extern "C" bool fn_27_84DFC(Cls* self) {
    return !self->isEnable();
}
