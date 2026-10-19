#pragma force_active on
struct stIceObj {
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
};

extern "C" bool fn_62_836C(stIceObj* self) {
    return !self->f3();
}
