#include <types.h>
#pragma force_active on

class fn_27_D3E70_Base {
public:
    virtual void vf0(s16 a, s8 b);
    virtual void vf1();
    virtual void vf2();
};

extern "C" void fn_27_D3E70(fn_27_D3E70_Base* p, s16 a, s8 b) {
    p->vf0(a, b);
}
