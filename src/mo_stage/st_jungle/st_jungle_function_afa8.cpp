#pragma force_active on
struct fnObjAFA8 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual int vfn3();
    virtual void vfn4();
    virtual void vfn5();
};

extern "C" bool fn_51_AFA8(fnObjAFA8* obj) {
    return obj->vfn3() == 0;
}
