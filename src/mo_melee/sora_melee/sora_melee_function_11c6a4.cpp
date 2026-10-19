#pragma force_active on
class soObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_27_11C6A4(soObj* p) {
    return !p->f3();
}
