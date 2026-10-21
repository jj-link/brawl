#include <types.h>
#pragma force_active on

struct Pair {
    u32 a;
    u32 b;
};

struct Trio {
    Pair p;
    u32 c;
};

struct Blob {
    Trio t[4];
};

class VSrc {
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
    virtual Blob* getSrc();
};

class VDst {
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
    virtual Blob* getDst(u32 idx);
};

extern "C" void fn_27_E03A8(VSrc* self, u32 unused, u32 idx) {
    Blob* src = self->getSrc();
    Blob* dst = ((VDst*)self)->getDst(idx);
    dst->t[0] = src->t[0];
    dst->t[1] = src->t[1];
    dst->t[2] = src->t[2];
    dst->t[3] = src->t[3];
}
