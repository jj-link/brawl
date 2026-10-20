#pragma force_active on
class soObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
    virtual void f4();
    virtual void f5();
};

extern "C" bool fn_27_86BA0(soObj* p) {
    return !p->f3();
}
