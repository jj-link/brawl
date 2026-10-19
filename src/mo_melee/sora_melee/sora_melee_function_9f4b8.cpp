#pragma force_active on
class soWorkBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" {
bool fn_27_9F4B8(soWorkBase* p) {
    return !p->f3();
}
}
