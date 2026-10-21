#pragma force_active on

class Interface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" int fn_801B5D44(Interface* self) {
    return self->f3() + 4;
}
