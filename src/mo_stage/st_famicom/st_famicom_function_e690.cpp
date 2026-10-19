#pragma force_active on
struct FamicomObject {
    virtual ~FamicomObject();
    virtual int unused0();
    virtual int unused1();
    virtual int unused2();
    virtual int unused3();
};

extern "C" bool fn_68_E690(FamicomObject* object) {
    return object->unused2() == 0;
}
