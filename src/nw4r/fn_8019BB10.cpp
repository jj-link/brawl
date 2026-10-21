#pragma force_active on

struct Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* f3();
};

extern "C" char* fn_8019BB10(Obj* self) {
    return self->f3() + 4;
}
