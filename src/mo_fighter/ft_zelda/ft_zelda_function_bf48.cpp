#pragma force_active on
struct FtVirtual {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
};

struct FtHolder {
    char pad[0x180C4];
    FtVirtual inner;
};

extern "C" void fn_104_BF48(FtHolder *self) {
    self->inner.slot2();
}
