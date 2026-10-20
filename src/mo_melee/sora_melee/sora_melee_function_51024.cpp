#include <types.h>
#pragma force_active on

class IFace {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual s32 call(s32* p, s32 m, s16* o, s32 b);
};

extern "C" s16 fn_27_51024(u8* self, s32 a, s8 b) {
    s16 out = 0;
    IFace* inner = *(IFace**)(self + 8);
    s32 r = inner->call(&a, -1, &out, b);
    return (s16)r;
}
