#include <types.h>
#pragma force_active on

struct VBase {
    virtual ~VBase();
    virtual void vf1();
    virtual void vf2();
    virtual s32 checkSomething();
};

extern "C" bool fn_27_CB6AC(VBase* self) {
    return self->checkSomething() == 0;
}
