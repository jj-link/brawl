#pragma force_active on
struct Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* f3();
};

extern "C" void* fn_80198908(Base* self) {
    return (char*)self->f3() + 4;
}
