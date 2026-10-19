#include <types.h>
#pragma force_active on

class soBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual bool f4();
};

extern "C" bool fn_27_850A0(soBase* p) {
    return !p->f4();
}
