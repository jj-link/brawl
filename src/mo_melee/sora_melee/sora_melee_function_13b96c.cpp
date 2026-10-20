#include <types.h>
#pragma force_active on

class VObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual s32 f5(u32, u32, u32, u32);
};

extern "C" s32 fn_27_13B96C(char* self) {
    VObj* obj = *(VObj**)(*(char**)(*(char**)(self + 0x60) + 0xd8) + 0x50);
    return obj->f5(0x1fae, 0, 0, 0);
}
