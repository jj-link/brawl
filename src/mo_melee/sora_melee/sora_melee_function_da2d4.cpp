#pragma force_active on
typedef short s16;
typedef int s32;
typedef signed char s8;
typedef unsigned char u8;

class Obj {
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
    virtual s32 f18(s32*, s32, s16*, s32) = 0;
};

extern "C" s16 fn_27_DA2D4(void* p, s32 v, s8 c) {
    s16 b = 0;
    Obj* obj = *(Obj**)((u8*)p + 8);
    return (s16)obj->f18(&v, -1, &b, (s32)c);
}
