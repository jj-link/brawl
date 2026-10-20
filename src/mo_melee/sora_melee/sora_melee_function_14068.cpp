#pragma force_active on
extern "C" void fn_27_13EF4(void* self);

struct Object {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void reset(int);
};

struct State {
    unsigned char pad0[0x38];
    unsigned int value;
    unsigned char pad1[0xB4];
    Object* object;
    unsigned char pad2[0x70];
    unsigned char flags;
};

extern "C" void fn_27_14068(State* self) {
    fn_27_13EF4(self);
    self->object->reset(-1);
    self->value = 0;
    self->flags &= ~0x40;
}
