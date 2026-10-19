#pragma force_active on
struct ftPikminVirtBase {
    virtual int fn0();
    virtual int fn1();
    virtual int fn2();
    virtual int fn3();
    virtual int fn4();
    virtual int fn5();
};

extern "C" bool fn_113_2310C(ftPikminVirtBase* p) {
    return !p->fn3();
}
