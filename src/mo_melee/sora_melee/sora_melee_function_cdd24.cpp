#include <types.h>
#pragma force_active on

class soBase {
public:
    virtual u32 vf0();
    virtual u32 vf1();
    virtual u32 vf2();
    virtual u32 vf3();
    virtual u32 vf4();
    virtual u32 vf5();
};

extern "C" bool fn_27_CDD24(soBase* p) {
    return !p->vf3();
}
