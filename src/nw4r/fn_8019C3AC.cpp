#pragma force_active on

class Inner {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* f3();
};

extern "C" char* fn_8019C3AC(Inner* self) {
    return self->f3() + 4;
}
