#pragma force_active on
struct Base {
    unsigned char padding[0x3C];
};

struct Object : Base {
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
    virtual void slot25();
    virtual void slot26();
    virtual unsigned int query();

    unsigned char padding40[4];
    unsigned char state;
};

extern "C" bool fn_27_241664(Object* self) {
    if (self->query() == 0xFFFFFFFFU) {
        return true;
    }
    return self->state == 3;
}
