#pragma force_active on
class Base {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f5();
};

extern "C" {
bool fn_73_A784(Base* obj) {
    return !obj->f5();
}
}
