#pragma force_active on
struct VirtBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" bool fn_57_D044(VirtBase* p) {
    return !p->f3();
}
