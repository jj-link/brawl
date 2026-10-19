#pragma force_active on
struct Base {
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
};

extern "C" bool fn_52_7344(Base* self) {
    return !self->f3();
}
