#pragma force_active on
struct Obj {
    virtual ~Obj();
    virtual void f0();
    virtual void f1();
    virtual char* f2();
};

extern "C" {
char* fn_80199C3C(Obj* self) {
    return self->f2() + 4;
}
}
