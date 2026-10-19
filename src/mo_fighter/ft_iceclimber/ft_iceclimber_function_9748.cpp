#pragma force_active on
struct IceClimberWorkBase {
    void* primary;
    void* field04;
};

struct IceClimberWork : IceClimberWorkBase {
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

struct IceClimberObject {
    unsigned char padding[0x108];
    unsigned int values[0x22];
    unsigned int extra[3];
    IceClimberWork work;
};

extern "C" IceClimberWork* fn_105_9248(
    IceClimberWork*, void*, void*, void*, void*, void*, void*);

extern "C" IceClimberObject* fn_105_9748(IceClimberObject* self) {
    fn_105_9248(&self->work, self, (void*)0x42, self->values,
                (void*)0x22, self->extra, (void*)3);
    self->work.initialize();
    return self;
}
