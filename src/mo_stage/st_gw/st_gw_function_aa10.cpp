#pragma force_active on
struct StObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" bool fn_63_AA10(StObj* obj) {
    return !obj->f3();
}
