#include <types.h>
#pragma force_active on

struct Foo {
    virtual u32 f0();
    virtual u32 f1();
    virtual u32 f2();
    virtual u32 f3();
    virtual u32 f4();
    virtual u32 f5();
};

extern "C" u32 fn_27_14FB1C(Foo* that) {
    u32 result = that->f3();
    return result == 0;
}
