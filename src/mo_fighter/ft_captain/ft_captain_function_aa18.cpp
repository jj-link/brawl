#pragma force_active on
class Target {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" bool fn_100_AA18(Target* self) {
    return !self->f3();
}
