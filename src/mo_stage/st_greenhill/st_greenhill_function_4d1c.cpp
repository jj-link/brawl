#pragma force_active on
struct fn_72_Base {
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
};

extern "C" bool fn_72_4D1C(fn_72_Base* self) {
    return self->f3() == 0;
}
