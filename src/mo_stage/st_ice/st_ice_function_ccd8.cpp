#pragma force_active on
struct IceObject {
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
};

extern "C" bool fn_62_CCD8(IceObject* self) {
    return !self->f3();
}
