#include <types.h>
#pragma force_active on

class fn_27_Base {
public:
    virtual void fn_vt0(s16 a, s8 b);
};

extern "C" void fn_27_D46A0(fn_27_Base* p, s16 a, s8 b) {
    p->fn_vt0(a, b);
}
