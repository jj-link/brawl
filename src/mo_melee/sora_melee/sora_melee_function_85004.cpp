#include <types.h>
#pragma force_active on

class soVirtualBaseTest {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual bool vf4();
};

extern "C" bool fn_27_85004(soVirtualBaseTest* p) {
    return !p->vf4();
}
