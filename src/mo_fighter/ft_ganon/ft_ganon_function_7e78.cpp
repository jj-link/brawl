#pragma force_active on
struct Fn109Work {
    void* secondary;
    unsigned int reserved;

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

struct Fn109Object {
    unsigned char data[0x1C0];
    Fn109Work work;
};

extern "C" Fn109Work* fn_109_7978(
    Fn109Work*, void*, unsigned int, void*, unsigned int, void*, unsigned int);

extern "C" Fn109Object* fn_109_7E78(Fn109Object* object) {
    fn_109_7978(&object->work, object, 0x4D,
               object->data + 0x134, 0x20, object->data + 0x1B4, 3);
    object->work.initialize();
    return object;
}
