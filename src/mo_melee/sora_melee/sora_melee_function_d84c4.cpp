#pragma force_active on
struct Sub {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void f();
};

struct First {
    virtual void g();
    int pad[3];
};

struct Derived : First, Sub {
};

extern "C" void fn_27_D84C4(Derived& self) {
    static_cast<Sub&>(self).f();
}
