#pragma force_active on
struct StObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" bool fn_72_4D50(StObj* obj) {
    return obj->f3() == 0;
}
