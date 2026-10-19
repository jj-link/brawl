#pragma force_active on
struct BCA4Target {
    virtual int slot0();
    virtual int slot1();
    virtual int slot2();
    virtual int slot3();
    virtual int slot4();
};

extern "C" bool fn_116_BCA4(BCA4Target* self) {
    return !self->slot3();
}
