#pragma force_active on
struct DonkeyWork {
    unsigned int field0;
    unsigned int field4;

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

extern "C" DonkeyWork* fn_92_7FAC(
    DonkeyWork*, void*, void*, void*, void*, void*, void*
);

extern "C" void* fn_92_84AC(char* self)
{
    fn_92_7FAC(
        (DonkeyWork*)(self + 0x1C0),
        self,
        (void*)0x4D,
        self + 0x134,
        (void*)0x20,
        self + 0x1B4,
        (void*)3
    );
    ((DonkeyWork*)(self + 0x1C0))->initialize();
    return self;
}
