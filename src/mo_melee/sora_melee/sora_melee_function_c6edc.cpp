#include <types.h>
#pragma force_active on

struct Inner {
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
};

extern "C" void fn_27_C6EDC(Inner* self) {
    ((Inner*)((u8*)self + 0x50))->vf3();
}
