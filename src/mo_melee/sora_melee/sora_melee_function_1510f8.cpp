#pragma force_active on
class fn_27_Sub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

class fn_27_Outer {
public:
    char pad[0x30];
    fn_27_Sub sub;
};

extern "C" {
void fn_27_1510F8(fn_27_Outer* p) {
    p->sub.f4();
}
}
