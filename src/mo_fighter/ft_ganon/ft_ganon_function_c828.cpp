#pragma force_active on
class ObjA {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int v);
};

class ObjB {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int v, unsigned int w);
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
    virtual void slot19(unsigned int id);
};

extern "C" void fn_109_C828(void*, char* p) {
    char* inner = *reinterpret_cast<char**>(p + 0xD8);
    ObjB* target = *reinterpret_cast<ObjB**>(inner + 0x64);
    ObjA* a = *reinterpret_cast<ObjA**>(inner + 0x3C);
    a->slot5(-1);
    target->slot19(0x22000015);
    target->slot19(0x22000017);
    target->slot19(0x22000018);
    target->slot19(0x22000019);
    target->slot5(-1, 0x20000005);
}
