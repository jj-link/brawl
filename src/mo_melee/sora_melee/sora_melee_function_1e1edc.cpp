#include <types.h>
#pragma force_active on

// This class mirrors the primary-vtable layout of the object the original
// call goes through: a single primary vtable at offset 0 whose 16th
// entry (0x40) is getFloatWorkSize().
struct Base {
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual u32 getFloatWorkSize();
};

extern "C" u32 fn_27_1E1EDC(Base* work) {
    return work->getFloatWorkSize();
}
