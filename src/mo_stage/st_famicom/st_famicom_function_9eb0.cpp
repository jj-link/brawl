#pragma force_active on
struct fn68_Base {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual bool slot3();
};

extern "C" bool fn_68_9EB0(fn68_Base* self) {
    return !self->slot3();
}
