#pragma force_active on
class fn27Base {
public:
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
};

extern "C" void fn_27_84B9C(fn27Base* p) {
    return p->vfn1();
}
