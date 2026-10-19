#pragma force_active on
struct FnObj {
    virtual int fn0();
    virtual int fn1();
    virtual int fn2();
    virtual int fn3();
    virtual int fn4();
    virtual int fn5();
};

extern "C" bool fn_78_7A10(FnObj* obj) {
    return !obj->fn3();
}
