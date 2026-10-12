// Tail-calls entry 43 (offset 0xAC) of the interface vtable stored at
// offset 0x3C of the object. The selected implementation expects the original
// object pointer, so no `this` adjustment is performed (the vtable entry for
// this overridden slot receives the outer object directly).
//
// The local classes reproduce only the observed ABI contract: the primary
// base occupies 0x40 bytes so the interface subobject's vptr lands at 0x3C,
// and the interface places entry at vtable offset 0xAC.
namespace {
class ObjectPrefix {
public:
    unsigned char m_reserved[0x3C];
    virtual void m_primaryVirtual();
};

class InterfaceTable {
public:
    virtual void m_slot0();
    virtual void m_slot1();
    virtual void m_slot2();
    virtual void m_slot3();
    virtual void m_slot4();
    virtual void m_slot5();
    virtual void m_slot6();
    virtual void m_slot7();
    virtual void m_slot8();
    virtual void m_slot9();
    virtual void m_slot10();
    virtual void m_slot11();
    virtual void m_slot12();
    virtual void m_slot13();
    virtual void m_slot14();
    virtual void m_slot15();
    virtual void m_slot16();
    virtual void m_slot17();
    virtual void m_slot18();
    virtual void m_slot19();
    virtual void m_slot20();
    virtual void m_slot21();
    virtual void m_slot22();
    virtual void m_slot23();
    virtual void m_slot24();
    virtual void m_slot25();
    virtual void m_slot26();
    virtual void m_slot27();
    virtual void m_slot28();
    virtual void m_slot29();
    virtual void m_slot30();
    virtual void m_slot31();
    virtual void m_slot32();
    virtual void m_slot33();
    virtual void m_slot34();
    virtual void m_slot35();
    virtual void m_slot36();
    virtual void entry();
};

class DispatchObject : public ObjectPrefix, public InterfaceTable {
public:
    void entry();
};
}  // namespace

extern "C" void fn_99_106B8(DispatchObject* object) {
    object->entry();
}
