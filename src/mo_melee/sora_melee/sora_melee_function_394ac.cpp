#include <types.h>
#pragma force_active on

struct Pair {
    u32 x;
    u32 y;
};

struct VtblSlots {
    virtual void d0() = 0;
    virtual void d1() = 0;
    virtual void d2() = 0;
    virtual void d3() = 0;
    virtual void d4() = 0;
    virtual void d5() = 0;
    virtual void d6() = 0;
    virtual void d7() = 0;
    virtual void d8() = 0;
    virtual void d9() = 0;
    virtual void d10() = 0;
    virtual void d11() = 0;
    virtual void d12() = 0;
    virtual void d13() = 0;
    virtual void d14() = 0;
    virtual void d15() = 0;
    virtual void d16() = 0;
    virtual void d17() = 0;
    virtual void d18() = 0;
    virtual void d19() = 0;
    virtual void d20() = 0;
    virtual void d21() = 0;
    virtual void d22() = 0;
    virtual void d23() = 0;
    virtual void d24() = 0;
    virtual void d25() = 0;
};

struct SrcBase : VtblSlots {
    virtual Pair* getA() = 0;
};

struct DstBase : VtblSlots {
    virtual Pair* getB(void* arg) = 0;
};

extern "C" {
Pair* fn_27_394AC(SrcBase* self, int unused, void* arg) {
    Pair* src = self->getA();
    Pair* dst = reinterpret_cast<DstBase*>(self)->getB(arg);
    dst->x = src->x;
    dst->y = src->y;
    return dst;
}
}
