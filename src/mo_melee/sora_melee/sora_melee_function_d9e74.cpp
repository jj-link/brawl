#include <types.h>
#pragma force_active on

class soInner {
public:
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
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual s32 f18(u32* a, s32 b, s16* c, s32 d) = 0;
};

class soOuter {
public:
    u8 m_pad[8];
    soInner* m_inner;
};

extern "C" s16 fn_27_D9E74(soOuter* p, u32 a, s8 b) {
    s16 out = 0;
    return p->m_inner->f18(&a, -1, &out, b);
}
