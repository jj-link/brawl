#pragma force_active on
struct Interface {
    virtual int unused0();
    virtual int unused1();
    virtual int unused2();
    virtual int unused3();
    virtual int unused4();
};

extern "C" int fn_51_B010(Interface* object) {
    return object->unused3() == 0;
}
