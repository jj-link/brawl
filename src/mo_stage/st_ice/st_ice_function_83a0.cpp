#pragma force_active on
struct IceVirtualBase {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
};

extern "C" bool fn_62_83A0(IceVirtualBase* self) {
    return self->slot3() == 0;
}
