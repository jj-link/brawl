#pragma force_active on
class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
};

class Outer {
public:
    int m0;
    int m4;
    int m8;
    int mc;
    Sub sub;
};

extern "C" void fn_27_10E30C(Outer* p) {
    p->sub.v8();
}
