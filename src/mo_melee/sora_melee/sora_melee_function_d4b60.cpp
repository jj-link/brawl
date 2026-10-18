#include <types.h>
#pragma force_active on

class fn_27_D4B60_Base {
public:
    virtual void vf0(s16 a, s8 b);
    virtual void vf1();
};

extern "C" void fn_27_D4B60(fn_27_D4B60_Base* obj, s16 a, s8 b) {
    obj->vf0(a, b);
}
