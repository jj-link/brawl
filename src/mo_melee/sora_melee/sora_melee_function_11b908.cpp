#pragma force_active on
struct Base {
    virtual void a();
    virtual void b();
};

struct Derived : Base {
    virtual void c();
};

extern "C" void fn_27_11B908(Base* self) {
    self->b();
}
