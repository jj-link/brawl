#pragma force_active on
struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void* f3();
    virtual void f4();
    virtual void f5();
};

extern "C" void* fn_8019D850(Obj* self) {
    return (char*)self->f3() + 4;
}
