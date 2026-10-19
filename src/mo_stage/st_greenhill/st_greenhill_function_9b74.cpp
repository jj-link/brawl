#pragma force_active on
struct fn_Base {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v5();
};

extern "C" {
bool fn_72_9B74(fn_Base* obj) {
    return !obj->v5();
}
}
