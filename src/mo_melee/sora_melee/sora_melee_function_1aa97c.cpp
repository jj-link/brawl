#pragma force_active on
class Sub {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};

class Base {
public:
    virtual void b0();
    int a, b;
};

class Outer : public Base, public Sub {
public:
    virtual void v4();
};

extern "C" {
void fn_27_1AA97C(Outer& p) {
    Sub& s = p;
    s.v4();
}
}
