#pragma force_active on
struct Pr {
    virtual void g();
    int x[3];
};

struct Ab {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

struct Top : public Pr, public Ab {
};

extern "C" {
void fn_27_1B1638(Top* self) {
    Ab& r = *self;
    r.f3();
}
}
