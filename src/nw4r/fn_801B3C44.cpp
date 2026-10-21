#pragma force_active on

class SomeClass {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* f3();
};

extern "C" char* fn_801B3C44(SomeClass* self) {
    return self->f3() + 4;
}
