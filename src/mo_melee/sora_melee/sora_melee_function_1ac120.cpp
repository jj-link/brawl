#pragma force_active on
class Iface {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
};

class First {
public:
    virtual void f0();
    int a;
    int b;
    int c;
};

class D : public First, public Iface {
public:
    void v0();
    void v1();
    void v2();
    void v3();
    void v4();
    void v5();
    void v6();
    void v7();
    void v8();
    void v9();
    void v10();
    void v11();
    void v12();
    void v13();
    void v14();
    void v15();
};

extern "C" void fn_27_1AC120(D& p) {
    Iface& i = p;
    i.v13();
}
