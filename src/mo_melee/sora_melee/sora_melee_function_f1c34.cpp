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
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
};

extern "C" {
void fn_27_F1C34(char* self) {
    ((fn_27_Inner*)(self + 0x10))->f8();
}
}
