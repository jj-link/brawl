#pragma force_active on
struct StNorfairObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_54_B0EC(StNorfairObj* obj) {
    return !obj->v3();
}
