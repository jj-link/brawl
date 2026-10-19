#pragma force_active on
struct stVirtBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" bool fn_78_7A44(stVirtBase* obj) {
    return obj->f3() == 0;
}
