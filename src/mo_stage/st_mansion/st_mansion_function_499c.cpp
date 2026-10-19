#pragma force_active on
struct fn_47_Base {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual int vfn3();
};

extern "C" bool fn_47_499C(fn_47_Base* p) {
    return p->vfn3() == 0;
}
