#include <types.h>
#pragma force_active on

class IFace {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool isReady() = 0; // vtable 0x18
};

extern "C" bool fn_27_84D94(IFace* self) {
    return !self->isReady();
}
