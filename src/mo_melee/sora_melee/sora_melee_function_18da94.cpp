#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_25D0;

namespace {
    struct VObj {
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
        virtual void f15(float* v, s32 n) = 0;
    };
}

extern "C" void fn_27_18DA94(void* unused, u8* obj) {
    float v[3];
    float zero = lbl_27_rodata_25D0;
    v[0] = zero;
    v[1] = zero;
    v[2] = zero;
    VObj* inner = *(VObj**)(*(u8**)(obj + 0xd8) + 0xc);
    inner->f15(v, 0);
}
