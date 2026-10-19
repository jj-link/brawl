#pragma force_active on
struct ftToonVirtBase {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual int vfn3();
};

extern "C" bool fn_121_CBF8(ftToonVirtBase* self) {
    return self->vfn3() == 0;
}
