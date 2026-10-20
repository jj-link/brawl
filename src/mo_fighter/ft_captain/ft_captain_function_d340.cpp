#pragma force_active on
class CaptainObjectBase {
public:
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
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual bool slot17(unsigned int id);
    virtual void slot18(unsigned int id);
};

extern "C" void fn_100_D340(void*, char* object) {
    char* inner = *reinterpret_cast<char**>(object + 0xD8);
    CaptainObjectBase* target = *reinterpret_cast<CaptainObjectBase**>(inner + 0x64);
    if (target->slot17(0x22000011)) {
        target->slot18(0x22000010);
    }
}
