#pragma force_active on
class fnObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_66_A094(fnObj* p) {
    return !p->f3();
}
