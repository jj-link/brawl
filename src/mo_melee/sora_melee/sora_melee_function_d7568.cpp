#pragma force_active on
class Sec {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
};

class Prim {
public:
    virtual void p0();
    int a;
    int b;
};

class Derived : public Prim, public Sec {
public:
    virtual void f4();
};

extern "C" {
void fn_27_D7568(Derived& self) {
    static_cast<Sec&>(self).f4();
}
}
