#include <types.h>
#pragma force_active on

class PeachVirtualBase {
public:
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual bool fn3();
};

extern "C" bool fn_103_FD84(PeachVirtualBase* obj) {
    return !obj->fn3();
}
