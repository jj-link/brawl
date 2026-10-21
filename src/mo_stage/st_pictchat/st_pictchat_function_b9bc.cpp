#pragma force_active on
class Base {
public:
    virtual void pad0(), pad1(), pad2(), pad3(), pad4(),
        pad5(), pad6(), pad7(), pad8(), pad9(),
        pad10(), pad11(), pad12(), pad13(), pad14();
};

class Object : public Base {
public:
    virtual void slot0(), slot1(), slot2(), slot3(), slot4(),
        slot5(), slot6(), slot7(), slot8(), slot9();
};

extern "C" void fn_73_B9BC(Object* self) {
    self->slot9();
}
