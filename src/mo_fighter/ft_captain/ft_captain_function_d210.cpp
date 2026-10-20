#pragma force_active on
// Minimal ABI-level declarations for the call chain used by fn_100_D210.
// Empirically, declared slot k is emitted at vtable offset 4 * (k + 2),
// so offset 0x3C maps to declared slot 13 and offset 0x50 maps to slot 18.

class soCallTarget {
public:
    virtual void slot0(unsigned int);
    virtual void slot1(unsigned int);
    virtual void slot2(unsigned int);
    virtual void slot3(unsigned int);
    virtual void slot4(unsigned int);
    virtual void slot5(unsigned int);
    virtual void slot6(unsigned int);
    virtual void slot7(unsigned int);
    virtual void slot8(unsigned int);
    virtual void slot9(unsigned int);
    virtual void slot10(unsigned int);
    virtual void slot11(unsigned int);
    virtual void slot12(unsigned int);
    virtual void slot13(unsigned int);
    virtual void slot14(unsigned int);
    virtual void slot15(unsigned int);
    virtual void slot16(unsigned int);
    virtual void slot17(unsigned int);
    virtual void slot18(unsigned int);
    virtual void slot19(unsigned int);
    virtual void slot20(unsigned int);
};

class soCallHolder {
public:
    unsigned char storage[0x64];
    soCallTarget* target;   // at 0x64
};

class ftCaptainOwner {
public:
    unsigned char storage[0xD8];
    soCallHolder* holder;   // at 0xD8
};

extern "C" void fn_100_D210(ftCaptainOwner* self) {
    self->holder->target->slot13(0x11000000);
    self->holder->target->slot18(0x12000003);
}
