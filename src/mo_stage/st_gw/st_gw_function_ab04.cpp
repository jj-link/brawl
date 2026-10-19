#pragma force_active on
struct stVirtObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
};

extern "C" bool fn_63_AB04(stVirtObj* obj) {
    return !obj->v3();
}
