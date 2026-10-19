#pragma force_active on
struct fn66Base {
    virtual int fn0();
    virtual int fn1();
    virtual int fn2();
    virtual int fn3();
    virtual int fn4();
    virtual int fn5();
};

extern "C" bool fn_66_EE84(fn66Base* obj) {
    return !obj->fn3();
}
