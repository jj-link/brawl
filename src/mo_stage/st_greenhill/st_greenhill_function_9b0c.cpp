#pragma force_active on
struct fnBaseVirt {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" bool fn_72_9B0C(fnBaseVirt* obj) {
    return !obj->f3();
}
