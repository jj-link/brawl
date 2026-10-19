#include <types.h>
#pragma force_active on

class fnVirtBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_27_1A744C(fnVirtBase* p) {
    return !p->v3();
}
