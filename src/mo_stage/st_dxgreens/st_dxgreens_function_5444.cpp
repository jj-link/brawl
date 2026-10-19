#pragma force_active on
struct fn_79_5444_Obj {
    virtual int vfn0();
    virtual int vfn1();
    virtual int vfn2();
    virtual int vfn3();
    virtual int vfn4();
    virtual int vfn5();
};

extern "C" bool fn_79_5444(fn_79_5444_Obj* obj) {
    return !obj->vfn3();
}
