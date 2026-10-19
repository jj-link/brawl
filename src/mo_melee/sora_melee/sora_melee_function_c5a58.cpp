#include <types.h>
#pragma force_active on

struct IObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool check();
};

extern "C" bool fn_27_C5A58(IObj* obj) {
    return !obj->check();
}
