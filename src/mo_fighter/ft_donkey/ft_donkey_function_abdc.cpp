#pragma force_active on
struct ftDonkeyBase {
    virtual void fn0();
    virtual void fn1();
    virtual void fn2();
    virtual bool fn3();
};

extern "C" bool fn_92_ABDC(ftDonkeyBase* self) {
    return !self->fn3();
}
