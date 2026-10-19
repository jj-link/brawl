#pragma force_active on
struct SomeObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" int fn_40_11E1C(SomeObj* obj) {
    return !obj->f3();
}
