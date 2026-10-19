#pragma force_active on
struct MarioModule {
    unsigned int data[2];
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
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void initialize();
};

extern "C" {
void* fn_91_45E8(void*, void*, int, void*, int, void*, int);

void* fn_91_58E8(void* object) {
    unsigned char* self = static_cast<unsigned char*>(object);
    fn_91_45E8(self + 0x1c0, object, 0x4d, self + 0x134,
               0x20, self + 0x1b4, 3);
    reinterpret_cast<MarioModule*>(self + 0x1c0)->initialize();
    return object;
}
}
