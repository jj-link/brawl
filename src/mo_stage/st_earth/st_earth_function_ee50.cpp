#pragma force_active on
struct StEarthObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_66_EE50(StEarthObj* obj) {
    return !obj->v3();
}
