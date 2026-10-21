#pragma force_active on
class Base {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2(void* x);
    virtual void f3();
    virtual void f4();
};

extern "C" {
void fn_80183164(void* a, Base* obj) {
    obj->f2(a);
}
}
