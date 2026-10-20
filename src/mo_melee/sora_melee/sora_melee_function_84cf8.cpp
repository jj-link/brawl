#pragma force_active on
class soIfaceBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual bool f4();
};

extern "C" bool fn_27_84CF8(soIfaceBase* self) {
    return !self->f4();
}
