#include <types.h>
#pragma force_active on

struct WorkInts {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};

struct WorkData {
    WorkInts ints;
    u32 e;
    float f0;
    float f1;
    float f2;
    float f3;
    u8 flag;
    u32 value;
};

class WorkProvider {
public:
    virtual void f00() {}
    virtual void f01() {}
    virtual void f02() {}
    virtual void f03() {}
    virtual void f04() {}
    virtual void f05() {}
    virtual void f06() {}
    virtual void f07() {}
    virtual void f08() {}
    virtual void f09() {}
    virtual void f10() {}
    virtual void f11() {}
    virtual void f12() {}
    virtual void f13() {}
    virtual void f14() {}
    virtual void f15() {}
    virtual void f16() {}
    virtual void f17() {}
    virtual void f18() {}
    virtual void f19() {}
    virtual void f20() {}
    virtual void f21() {}
    virtual void f22() {}
    virtual void f23() {}
    virtual void f24() {}
    virtual void f25() {}
    virtual WorkData* get(u32 index);
};

extern "C" WorkData* fn_27_EDA10(WorkProvider* provider, u32 srcIndex, u32 dstIndex) {
    WorkData* src = provider->get(srcIndex);
    WorkData* dst = provider->get(dstIndex);
    *dst = *src;
    return dst;
}
