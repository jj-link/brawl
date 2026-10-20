#pragma force_active on
struct Interface {
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
    virtual void slot11();
};

struct Holder {
    char pad[0x2C];
    Interface* object;
};

extern "C" void fn_27_75D8C(Holder* self) {
    self->object->slot11();
}
