#pragma force_active on
struct ftKirbyVtblObj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
};

extern "C" bool fn_96_1F83C(ftKirbyVtblObj* self) {
    return !self->slot3();
}
