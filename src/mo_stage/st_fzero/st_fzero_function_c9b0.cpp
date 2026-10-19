#pragma force_active on
struct StObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_61_C9B0(StObj* obj) {
    return !obj->f3();
}
