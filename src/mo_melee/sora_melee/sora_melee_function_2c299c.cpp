#include <types.h>
#pragma force_active on

class soGeneralWorkAbstractLike {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" {
bool fn_27_2C299C(soGeneralWorkAbstractLike* p) {
    return !p->f3();
}
}
