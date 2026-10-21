#pragma force_active on
class Obj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Obj* f3();
    virtual void f4();
    virtual void f5();
};

extern "C" char* fn_8019C32C(Obj* self) {
    return (char*)self->f3() + 4;
}
