#pragma force_active on
struct fnObjBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_68_D53C(fnObjBase* obj) {
    return obj->f3() == 0;
}
