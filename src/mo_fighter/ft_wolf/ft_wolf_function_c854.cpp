#pragma force_active on
struct ftWolfBase {
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual bool vfn5();
};

extern "C" bool fn_125_C854(ftWolfBase* p) {
    return !p->vfn5();
}
