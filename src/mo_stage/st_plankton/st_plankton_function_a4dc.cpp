#pragma force_active on
class StBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_74_A4DC(StBase* self) {
    return !self->f3();
}
