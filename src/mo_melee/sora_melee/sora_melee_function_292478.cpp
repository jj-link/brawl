#pragma force_active on
class fn_27_Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

extern "C" {
void fn_27_292478(char* p) {
    ((fn_27_Inner*)(p + 0xc))->f4();
}
}
