#pragma force_active on
struct StObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual void v4();
    virtual int v5();
};

extern "C" bool fn_51_B078(StObj* obj) {
    return !obj->v3();
}
