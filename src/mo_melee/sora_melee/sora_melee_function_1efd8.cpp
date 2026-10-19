#include <types.h>
#pragma force_active on

class soVirtBase {
public:
    virtual ~soVirtBase();
    virtual void vf0();
    virtual void vf1();
    virtual s32 vf2();
};

extern "C" bool fn_27_1EFD8(soVirtBase* p) {
    return !p->vf2();
}
