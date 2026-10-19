#pragma force_active on
struct NorfairBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool v3();
};

extern "C" bool fn_54_B0B8(NorfairBase* obj) {
    return !obj->v3();
}
