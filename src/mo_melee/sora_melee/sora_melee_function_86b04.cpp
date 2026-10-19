#include <types.h>
#pragma force_active on

class soVirtBase {
public:
    virtual void fn0() = 0;
    virtual void fn1() = 0;
    virtual void fn2() = 0;
    virtual bool isEmpty() = 0;
};

extern "C" bool fn_27_86B04(soVirtBase* x) { return !x->isEmpty(); }
