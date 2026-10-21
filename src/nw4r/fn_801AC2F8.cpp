#pragma force_active on

struct Inner {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* f3();
};

extern "C" char* fn_801AC2F8(Inner* self) {
    return self->f3() + 4;
}
