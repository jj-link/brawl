#include <types.h>
#pragma force_active on

struct Foo {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int isX();
};

extern "C" bool fn_27_1068DC(Foo* obj) {
    return !obj->isX();
}
