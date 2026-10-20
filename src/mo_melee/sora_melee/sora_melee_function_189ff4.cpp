#pragma force_active on
class IFace {
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
};

struct Mid {
    char pad[0x40];
    IFace* obj;
};

struct Top {
    char pad[0xd8];
    Mid* mid;
};

extern "C" {
void fn_27_189FF4(void* unused, Top* p4) {
    p4->mid->obj->f15();
}
}
