#pragma force_active on
struct fn_48_3DF8_Base {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual bool slot3();
};

extern "C" bool fn_48_3DF8(fn_48_3DF8_Base* self) {
    return !self->slot3();
}
