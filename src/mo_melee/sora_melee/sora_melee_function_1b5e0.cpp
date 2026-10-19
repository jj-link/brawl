#include <types.h>
#pragma force_active on

class fn27Base {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual u32 vf3();
};

extern "C" {
bool fn_27_1B5E0(fn27Base* p) {
    return !p->vf3();
}
}
