#pragma force_active on
class B0 { public: virtual void g0(); };
class B1 { public: virtual void g1(); };
class B2 { public: virtual void g2(); };
class B3 { public: virtual void g3(); };
class A {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};
class D : public B0, public B1, public B2, public B3, public A {
public:
    virtual void g0();
};

extern "C" void fn_27_294FD8(D& p) {
    static_cast<A&>(p).f1();
}
