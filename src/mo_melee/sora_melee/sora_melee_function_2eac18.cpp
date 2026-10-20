#pragma force_active on
class Work {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void divFloatWork(float, unsigned int);
};

struct Foo {
    unsigned int pad[4];
    Work work;
};

extern "C" void fn_27_2EAC18(Foo* f, float v, unsigned int i) {
    f->work.divFloatWork(v, i);
}
