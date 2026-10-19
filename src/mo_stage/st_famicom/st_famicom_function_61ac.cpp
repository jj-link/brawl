#pragma force_active on
struct fn68_61AC_Base {
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual int vfunc3();
};

extern "C" bool fn_68_61AC(fn68_61AC_Base* obj) {
    return obj->vfunc3() == 0;
}
