#pragma force_active on
struct stVirtBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" bool fn_71_F530(stVirtBase* p) {
    return p->f3() == 0;
}
