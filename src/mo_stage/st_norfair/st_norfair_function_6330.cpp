#pragma force_active on
struct stNorfairVirtBase {
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual int vfunc5();
};

extern "C" bool fn_54_6330(stNorfairVirtBase* self) {
    return self->vfunc5() == 0;
}
