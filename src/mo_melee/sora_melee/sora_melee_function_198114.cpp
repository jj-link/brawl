#pragma force_active on
class soFoo {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" {
    bool fn_27_198114(soFoo* p) {
        return !p->f3();
    }
}
