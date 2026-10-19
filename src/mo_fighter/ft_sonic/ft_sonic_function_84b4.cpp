#pragma force_active on
struct FtSonicWork {
    char padding[8];

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

extern "C" FtSonicWork* fn_123_7FB4(
    FtSonicWork*, void*, unsigned int, void*, unsigned int, void*, unsigned int);

extern "C" void* fn_123_84B4(void* object) {
    char* self = static_cast<char*>(object);

    fn_123_7FB4(
        reinterpret_cast<FtSonicWork*>(self + 0x1C0),
        object,
        0x4D,
        self + 0x134,
        0x20,
        self + 0x1B4,
        3);

    reinterpret_cast<FtSonicWork*>(self + 0x1C0)->initialize();

    return object;
}
