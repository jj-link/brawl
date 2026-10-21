#pragma force_active on

class MyClass {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* f3();
};

extern "C" char* fn_801B5588(MyClass* self) {
    return self->f3() + 4;
}
