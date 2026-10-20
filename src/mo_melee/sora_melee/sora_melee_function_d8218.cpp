#pragma force_active on
class soSub {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
};

class soOuter {
public:
    char pad[0xc];
    soSub m_sub;
};

extern "C" {
void fn_27_D8218(soOuter* p) {
    p->m_sub.f4();
}
}
