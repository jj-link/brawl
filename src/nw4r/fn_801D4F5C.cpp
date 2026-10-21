#include <types.h>
#pragma force_active on

extern "C" {

class Foo {
public:
    virtual s32 f0();
    virtual s32 f1();
    virtual s32 f2();
};

s32 fn_801D4F5C(Foo* p) {
    return p->f2();
}

}