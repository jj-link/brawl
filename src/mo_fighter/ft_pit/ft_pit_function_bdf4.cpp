#pragma force_active on
struct ftPitVirtBase {
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual bool vfunc3();
};

extern "C" bool fn_112_BDF4(ftPitVirtBase* self) {
    return !self->vfunc3();
}
