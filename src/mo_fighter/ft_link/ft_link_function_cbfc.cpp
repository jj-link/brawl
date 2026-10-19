#pragma force_active on
struct VirtualObject {
    virtual int unused0();
    virtual int unused1();
    virtual int unused2();
    virtual int unused3();
};

extern "C" bool fn_93_CBFC(VirtualObject* object) {
    return !object->unused3();
}
