#pragma force_active on
struct fn_49_Obj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
};

extern "C" bool fn_49_B794(fn_49_Obj* obj) {
    return !obj->f3();
}
