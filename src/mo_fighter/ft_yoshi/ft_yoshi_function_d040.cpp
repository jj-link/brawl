#pragma force_active on
struct fn95Base {
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
};

extern "C" bool fn_95_D040(fn95Base* p) {
    return !p->f3();
}
