#pragma force_active on
struct Obj {
    virtual int unused0();
    virtual int unused1();
    virtual int unused2();
    virtual int unused3();
};

extern "C" bool fn_102_A1E8(Obj* object) {
    return !object->unused3();
}
