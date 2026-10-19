#pragma force_active on
struct fn_49_Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3();
};

extern "C" bool fn_49_B7C8(fn_49_Base* obj) {
    return !obj->f3();
}
