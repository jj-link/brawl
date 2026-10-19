#pragma force_active on
struct stVirtBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_78_5498(stVirtBase* obj) {
    return !obj->f3();
}
