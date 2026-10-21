#pragma force_active on
class Iface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* f5();
};

extern "C" char* fn_8019D9A8(Iface* self) {
    return self->f5() + 4;
}
