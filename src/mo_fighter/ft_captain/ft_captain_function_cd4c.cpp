#pragma force_active on
class CaptainVirtualBase {
public:
    virtual void slot0();
    virtual void slot3(void* arg);
    virtual void slot2();
    virtual void slot3b();
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
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual int slot24();
};

extern "C" void fn_100_CD4C(CaptainVirtualBase* self, char* arg) {
    CaptainVirtualBase* sub = *reinterpret_cast<CaptainVirtualBase**>(*reinterpret_cast<char**>(arg + 0xD8) + 0x7C);
    if (sub->slot24() != 100) {
        self->slot3(arg);
    }
}
