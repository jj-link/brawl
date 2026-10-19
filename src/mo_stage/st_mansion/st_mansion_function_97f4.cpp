#pragma force_active on
struct stMansionObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" bool fn_47_97F4(stMansionObj* obj) {
    return !obj->f3();
}
