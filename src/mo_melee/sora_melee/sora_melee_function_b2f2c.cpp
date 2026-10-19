#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_B16C8(void* p);

class soCallbackBase {
public:
    virtual void f0();
    virtual void* f1();
};

struct soCallbackOwner {
    u8 pad[0x18];
    soCallbackBase* callback;
};

extern "C" void fn_27_B2F2C(void* self) {
    soCallbackOwner* owner = (soCallbackOwner*)self;
    void* p = owner->callback->f1();
    u32* work = (u32*)fn_27_B16C8(p);
    work[2] |= 0x8000;
}
