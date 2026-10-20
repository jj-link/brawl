#pragma force_active on
class Sub {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
};

extern "C" void fn_27_1A9080(char* self) {
    Sub* sub = (Sub*)(self + 0xc);
    sub->f4();
}
