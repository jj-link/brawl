#pragma force_active on
struct DxObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_79_5350(DxObj* obj) {
    return !obj->v3();
}
