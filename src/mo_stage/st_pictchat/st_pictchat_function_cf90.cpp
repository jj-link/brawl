#pragma force_active on
struct fn_73_Base {
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual int vfunc3();
};

extern "C" bool fn_73_CF90(fn_73_Base* obj) {
    return obj->vfunc3() == 0;
}
